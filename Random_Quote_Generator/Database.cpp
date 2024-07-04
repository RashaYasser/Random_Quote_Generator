#include "Database.h"
#include <fstream>
#include <iostream>

// Constructor to initialize the file path.
Database::Database(const std::string& filePath) : filePath(filePath) {}

// Loads quotes from the file into a map.
std::map<std::string, std::vector<std::string>> Database::loadQuotes()
{
    std::map<std::string, std::vector<std::string>> quotes;

    std::ifstream file(filePath); // Open the file for reading.

    if (file.is_open())
    {
        std::string emotion, quote;

        while (std::getline(file, emotion) && std::getline(file, quote))
        {
            quotes[emotion].push_back(quote); // Add each quote to the map.
        }

        file.close(); // Close the file after reading.

        // Print out loaded quotes for verification.
        std::cout << "Loaded Quotes........" << std::endl;

        //to print all quotes on terminal 
        // for (const auto& pair : quotes)
        // {
        //     //print emotion => key
        //     std::cout << pair.first << ":" << std::endl;
        //     for (const auto& quote : pair.second)
        //     {
        //         //print quote 
        //         std::cout << " - " << quote << std::endl;
        //     }

        // }
    } 
    else 
    {
        std::cout << "Error: Unable to open quotes.txt file." << std::endl;
    }
    return quotes;
}

// Saves quotes from the map to the file.
void Database::saveQuotes(const std::map<std::string, std::vector<std::string>>& quotes)
{
    std::ofstream file(filePath); // Open the file for writing.

    for (const auto& pair : quotes) 
    {
        for (const auto& quote : pair.second) 
        {
            file << pair.first << ":" << quote <<std::endl; // Write each quote to the file.
        }
    }
}
