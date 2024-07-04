#ifndef HAPPY_QUOTE_FACTORY_H
#define HAPPY_QUOTE_FACTORY_H

#include "QuoteFactory.h"
/*
 *Description:
    These concrete factories inherit from QuoteFactory and implement the createQuote() method 
    to return quotes based on specific emotions.

 *Design Pattern: Factory
    Encapsulates the creation logic for different types of quotes, making the system easier to extend.
*/



// Concrete factory that creates a happy quote.
class HappyQuoteFactory : public QuoteFactory
{
public:
    std::string createQuote() override;
};

#endif
