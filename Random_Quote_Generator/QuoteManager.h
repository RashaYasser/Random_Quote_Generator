#ifndef QUOTE_MANAGER_H
#define QUOTE_MANAGER_H

#include <map>
#include <vector>
#include <memory>
#include "Command.h"
#include "QuoteMemento.h"
#include "Database.h"
#include "Sender.h"
/*
 *Description:
    This Singleton class manages quotes, including loading, adding, and retrieving quotes.
    It supports backup operations through the Command pattern and the Memento pattern.
 
 *Design Patterns: Singleton, Command, Memento
    Singleton ensures only one instance manages the quotes.
    Command allows encapsulation of backup operations.
    Memento captures and restores the state of quotes.
*/
// Singleton class responsible for managing quotes.
class QuoteManager 
{
private:
    static QuoteManager* instance; // Static instance of the QuoteManager.
    std::map<std::string, std::vector<std::string>> quotes; // Map to store quotes.
    std::shared_ptr<Command> backupCommand; // Backup command to save quotes.
    Database database; // Database object to handle file operations.
    
    QuoteManager(); // Private constructor for singleton pattern.
    Sender* sender;

public:
    static QuoteManager* getInstance(); // Get the singleton instance.

    std::string getQuote(const std::string& emotion); // Get a quote for a specific emotion.
    QuoteMemento createMemento() const; // Create a memento of the current state.

    void addQuote(const std::string& emotion, const std::string& quote); // Add a new quote.
    std::map<std::string, std::vector<std::string>> restoreMemento(const QuoteMemento& memento); // Restore the state from a memento.

    void executeBackup(); // Execute the backup command.
    void setBackupCommand(std::shared_ptr<Command> command); // Set the backup command.

    std::map<std::string, std::string> getSenderStates() const;

};

#endif
