#include "HappyQuoteFactory.h"
#include "QuoteManager.h"

// Creates a happy quote using the QuoteManager.
std::string HappyQuoteFactory::createQuote() 
{
    return QuoteManager::getInstance()->getQuote("happy"); // Get a happy quote from the QuoteManager.
}
