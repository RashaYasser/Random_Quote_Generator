#include "QuoteManager.h"
#include <ctime>
#include <cstdlib>

// Initialize the static member of QuoteManager.
QuoteManager* QuoteManager::instance = nullptr;

// Private constructor to initialize the database and load quotes.
QuoteManager::QuoteManager() : database("quotes.txt") 
{
    quotes = database.loadQuotes(); // Load quotes from the file.
}

// Get the singleton instance of QuoteManager.
QuoteManager* QuoteManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new QuoteManager();
    }
    return instance;
}

// Get a random quote for a specific emotion.
std::string QuoteManager::getQuote(const std::string& emotion)
{
    if (quotes.find(emotion) != quotes.end() && !quotes[emotion].empty())
    {
        int index = std::rand() % quotes[emotion].size(); // Generate a random index.
        return quotes[emotion][index]; // Return the quote at the random index.
    } 
    else
    {
        return "No quotes available for this emotion."; // Return a default message if no quotes are available.
    }
}

// Create a memento of the current state.
QuoteMemento QuoteManager::createMemento() const
{
    return QuoteMemento(quotes);
}

// Add a new quote and save to the database.
void QuoteManager::addQuote(const std::string& emotion, const std::string& quote)
{
    quotes[emotion].push_back(quote);
    database.saveQuotes(quotes);
}

// Restore the state from a memento and save to the database.
std::map<std::string, std::vector<std::string>>  QuoteManager::restoreMemento(const QuoteMemento& memento) 
{
    quotes = memento.getState();
    //database.saveQuotes(quotes);
    return quotes;
}

// Execute the backup command.
void QuoteManager::executeBackup()
{
    if (backupCommand) 
    {
        backupCommand->execute();
    }
}

// Set the backup command.
void QuoteManager::setBackupCommand(std::shared_ptr<Command> command)
{
    backupCommand = command;
}

std::map<std::string, std::string> QuoteManager::getSenderStates() const
{
    // Retrieve the sender states from the Sender class
    return sender->getSenderStates();
}

