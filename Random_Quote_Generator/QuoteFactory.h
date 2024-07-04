#ifndef QUOTE_FACTORY_H
#define QUOTE_FACTORY_H

#include <string>
/*
 *Description:
    An abstract base class for creating quotes.
    It includes a pure virtual function createQuote() that must be implemented by derived classes.
    
 *Design Pattern: Factory
    This pattern allows the creation of objects without specifying 
    the exact class of the object that will be created.
 */


// Abstract base class for quote factories.
class QuoteFactory 
{
public:
    virtual std::string createQuote() = 0; // Pure virtual function to create a quote.
    
    virtual ~QuoteFactory() {} // Virtual destructor.
};

#endif
