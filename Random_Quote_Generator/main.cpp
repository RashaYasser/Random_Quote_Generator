/*
 ============================================================================
 Name        : main.c
 Layer       : APP
 Author      : RASHA_YASSER
 Description : Random quote Generator using Different Design Patterns (Singleton, Command, memento, and Factory Patterns).
 Date        : 5/19/2024
 ============================================================================
 */
#include <iostream>
#include <thread>
#include <chrono>
#include "QuoteManager.h"
#include "UserValidator.h"
#include "Receiver.h"
#include "Sender.h"
#include "BackupCommand.h"

int main()
 {

    // Ask the user for username and password
    std::string username, password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    // Create UserValidator with user-provided credentials
    std::shared_ptr<UserValidator> validator = std::make_shared<UserValidator>(username, password);

    // Check if the user credentials are valid
    if (!validator->validateUser())
    {
        std::cout << "Invalid username or password :( " << std::endl;
        return 0;
    }

      // Create Receiver and Sender
      auto receiver = std::make_shared<Receiver>(validator);
    
      Sender sender(validator);
      
      sender.setReceiver(receiver);
      // Get sender's name
      std::string senderName;
      std::cout << "Enter your name: ";
      std::cin >> senderName;

      // Get user feeling
      std::string emotion;
      std::cout << "Enter your Feeling (sad, happy): ";
      std::cin >> emotion;

    // Save current state of quotes
    auto memento = QuoteManager::getInstance()->createMemento();

   // Send request in a new thread
    std::thread senderThread(&Sender::sendRequest, &sender, emotion, senderName);

    // Wait for the sender thread to finish
    senderThread.join();

    // Simulate some delay 
    std::this_thread::sleep_for(std::chrono::seconds(2));

      // Execute backup and include sender's name and emotion
      std::shared_ptr<Command> backupCmd = std::make_shared<BackupCommand>(senderName, emotion);
      QuoteManager::getInstance()->setBackupCommand(backupCmd);
      QuoteManager::getInstance()->executeBackup();

    return 0;
}

