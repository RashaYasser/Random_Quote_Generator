#ifndef SENDER_H
#define SENDER_H

#include <string>
#include <memory>
#include "Receiver.h"
#include "UserValidator.h"
#include <thread>
#include <iostream>
#include <map>
/*
 *Description:
    This class sends requests to the Receiver.
    It runs the request handling on a separate thread and stores the state of senders.
    
*/

// Sends requests to the receiver using a separate thread for each request.
// Validates the user before sending the request.
class Sender 
{
private:
    std::shared_ptr<Receiver> receiver; // Receiver to handle the requests.
    std::shared_ptr<UserValidator> userValidator; // Validator for user credentials.
    std::map<std::string, std::string> senderStates;

public:

    Sender(std::shared_ptr<UserValidator> validator); // Constructor to initialize the user validator.
    void sendRequest(const std::string& emotion, const std::string& senderName); // Sends a request to the receiver.
    void setReceiver(std::shared_ptr<Receiver> recv); // Sets the receiver.
    std::map<std::string, std::string> getSenderStates() const;

};

#endif

