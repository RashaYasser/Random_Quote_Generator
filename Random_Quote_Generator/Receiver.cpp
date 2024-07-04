#include "Receiver.h"

// Constructor to initialize the validator.
Receiver::Receiver(std::shared_ptr<UserValidator> validator) : validator(validator) {}

// Receives and handles a request for a quote based on the provided emotion.
void Receiver::receiveRequest(const std::string& emotion, const std::string& senderName) 
{
    std::lock_guard<std::mutex> lock(mux); // Lock the mutex for thread safety.
    std::cout << "Sender :  " << senderName <<"  Feeling => "<<emotion<< std::endl;

    if (validator->validateUser())
     { // Validate the user credentials.
        std::shared_ptr<QuoteFactory> factory;

        if (emotion == "sad")
        {
            factory = std::make_shared<SadQuoteFactory>();
        } 
        else if (emotion == "happy") 
        {
            factory = std::make_shared<HappyQuoteFactory>();
        }

        if (factory)
        {
            std::cout << "Quote: " << factory->createQuote() << std::endl;
        }
    } 
    else
    {
        std::cout << "User validation failed." << std::endl;
    }
}
