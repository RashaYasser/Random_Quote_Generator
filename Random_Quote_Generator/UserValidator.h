#ifndef USERVALIDATOR_H
#define USERVALIDATOR_H

#include <string>
/*
 *Description:
    This class validates user credentials.
    It checks the provided username and password are valid values.
    
*/
// Class for validating user credentials.
class UserValidator
{
private:
    std::string username; // Stores the username.
    std::string password; // Stores the password.
    const std::string validUsername = "RASHA"; // Hardcoded valid username.
    const std::string validPassword = "1234"; // Hardcoded valid password.

public:
    UserValidator(const std::string& user, const std::string& pass); // Constructor to set the username and password.
    bool validateUser(); // Validates the user credentials.
};

#endif
