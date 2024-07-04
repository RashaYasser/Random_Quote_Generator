#ifndef QUOTEMEMENTO_H
#define QUOTEMEMENTO_H

#include <map>
#include <vector>
#include <string>
/*
 *Description:
    This class stores the state of quotes.
    It provides functionality to capture and restore the state of the QuoteManager.
 *Design Pattern: Memento
    It provides the ability to restore an object to its previous state,
    which is useful for undo operations and state persistence.
*/

// Class to store the state of quotes.
class QuoteMemento 
{
private:
    std::map<std::string, std::vector<std::string>> state; // Stores the state of quotes.

public:
    QuoteMemento(const std::map<std::string, std::vector<std::string>>& state); // Constructor to set the state.
    std::map<std::string, std::vector<std::string>> getState() const; // Get the stored state.
    std::map<std::string, std::vector<std::string>> restoreState(); // Restore the stored state.
};

#endif
