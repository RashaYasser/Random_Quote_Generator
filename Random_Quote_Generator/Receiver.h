#ifndef RECEIVER_H
#define RECEIVER_H

#include <mutex>
#include <string>
#include <memory>
#include "UserValidator.h"
#include "QuoteFactory.h"
#include "SadQuoteFactory.h"
#include "HappyQuoteFactory.h"
#include <iostream>
/*
 *Description:
    This class receives requests and uses a quote factory to create quotes based on the emotion specified.
    It validates the user before processing the request.
    Acts as a mediator that validates user requests and interacts with appropriate factories to fulfill the request.
*/
class Receiver
{
private:
    std::shared_ptr<UserValidator> validator; // Validator for user credentials.
    std::mutex mux; // Mutex for thread safety.

public:
    Receiver(std::shared_ptr<UserValidator> validator); // Constructor to initialize the validator.
    //void receiveRequest(const std::string& emotion); // Receives and handles a quote request.
    void receiveRequest(const std::string& emotion, const std::string& senderName);

};

#endif
