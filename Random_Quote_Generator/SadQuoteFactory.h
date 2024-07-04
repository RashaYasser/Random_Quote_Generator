#ifndef SADQUOTEFACTORY_H
#define SADQUOTEFACTORY_H

#include "QuoteFactory.h"
/*
 *Description:
    These concrete factories inherit from QuoteFactory and implement the createQuote() method 
    to return quotes based on specific emotions.

 *Design Pattern: Factory
    Encapsulates the creation logic for different types of quotes, making the system easier to extend.
*/


// Concrete factory for creating sad quotes.
class SadQuoteFactory : public QuoteFactory 
{
public:
    std::string createQuote() override; // Create a sad quote.
};

#endif
