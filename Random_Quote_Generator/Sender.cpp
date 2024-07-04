#include "Sender.h"

// Constructor to initialize the user validator.
Sender::Sender(std::shared_ptr<UserValidator> validator) : userValidator(validator) {}

// Sends a request to the receiver on a separate thread.
void Sender::sendRequest(const std::string& emotion, const std::string& senderName) 
{
    if (receiver)
    {
        if (userValidator->validateUser()) 
        {
            // std::thread t(&Receiver::receiveRequest, receiver, emotion); // Create a new thread to send the request.
            // t.join(); // Wait for the thread to finish.
            senderStates[senderName] = emotion;
            std::thread([this, emotion, senderName](){
                receiver->receiveRequest(emotion, senderName);
            }).detach();
        }
        else
        {
            std::cout << "User validation failed!" << std::endl;
        }
    }
     else
    {
        std::cout << "Receiver not set!" << std::endl;
    }
}

// Sets the receiver.
void Sender::setReceiver(std::shared_ptr<Receiver> recv) 
{
    receiver = recv;
}


// Get the states of all senders
std::map<std::string, std::string> Sender::getSenderStates() const
{
    return senderStates;
}