#include "BackupCommand.h"

 BackupCommand::BackupCommand(const std::string& senderName, const std::string& emotion) 
    : senderName(senderName), emotion(emotion) {}
// Execute the backup operation.
void BackupCommand::execute() 
{
    // Retrieve the sender states and the current state of quotes
    auto memento = QuoteManager::getInstance()->createMemento();
    // Open the backup file
    std::ofstream backupFile("backup_quotes.txt");
    if (backupFile.is_open()) 
    {
        // Iterate over all sender states and write them to the backup file
            backupFile << "Sender: " << senderName <<std::endl;
            backupFile << "Emotion: " << emotion <<std::endl;
        
        // Iterate over all quotes and write them to the backup file
        for (const auto& pair : memento.getState()) 
        {
            for (const auto& quote : pair.second) 
            {
                backupFile << pair.first << "\n" << quote <<std::endl;
            }
            
        }

        // Close the backup file
        backupFile.close();
    }
}
