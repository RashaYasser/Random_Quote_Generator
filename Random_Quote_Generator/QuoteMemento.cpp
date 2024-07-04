#include "QuoteMemento.h"

// Constructor to initialize the state.
QuoteMemento::QuoteMemento(const std::map<std::string, std::vector<std::string>>& state) : state(state) {}

// Get the stored state.
std::map<std::string, std::vector<std::string>> QuoteMemento::getState() const
{
    return state;
}

// Restore the stored state.
std::map<std::string, std::vector<std::string>> QuoteMemento::restoreState()
{
    return state;
}
