#ifndef BACKUPCOMMAND_H
#define BACKUPCOMMAND_H
#include "Command.h"
#include "QuoteManager.h"
#include <fstream>
#include <string>

/*
 *Description:
    This concrete class inherits from Command and is responsible for backing up the quotes.
    It stores the sender's name and emotion, and writes the current state of quotes to a backup file.
    
 *Design Pattern: Command
    This pattern is used to encapsulate the request to back up data,
    providing flexibility and decoupling the backup action from the QuoteManager.
*/

// Concrete command that performs backup of quotes.
class BackupCommand : public Command
 {
public:
    BackupCommand(const std::string& senderName, const std::string& emotion);// Constructor to initialize sender name and emotion.


    void execute() override; // Execute the backup operation.
private:
    std::string senderName; // Name of the sender.
    std::string emotion; // Emotion associated with the request.

};

#endif
