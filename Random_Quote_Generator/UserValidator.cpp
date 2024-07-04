#include "UserValidator.h"

// Constructor to initialize username and password.
UserValidator::UserValidator(const std::string& user, const std::string& pass) : username(user), password(pass) {}

// Validates the provided username and password against the hardcoded values.
bool UserValidator::validateUser()
{
    return (username == validUsername && password == validPassword);
}
