#include "SadQuoteFactory.h"
#include "QuoteManager.h"

// Creates a sad quote using the QuoteManager.
std::string SadQuoteFactory::createQuote()
{
    return QuoteManager::getInstance()->getQuote("sad"); // Get a sad quote from the QuoteManager.
}
