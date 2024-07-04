#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <map>
#include <fstream>
#include <vector>

/*
Description:
    This class is responsible for loading and saving quotes to and from a file.
    Provides an interface to interact with the file system.

*/

// Class responsible for loading and saving quotes to a file.
class Database 
{
private:
    std::string filePath; // Path to the file where quotes are stored.

public:
    Database(const std::string& filePath); // Constructor to set the file path.

    std::map<std::string, std::vector<std::string>> loadQuotes(); // Load quotes from the file.
    
    void saveQuotes(const std::map<std::string, std::vector<std::string>>& quotes); // Save quotes to the file.
};

#endif
