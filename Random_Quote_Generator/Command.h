#ifndef COMMAND_H
#define COMMAND_H
/*
 *Description:
    This is an abstract base class for all command types.
    It includes a pure virtual function execute() that derived classes must implement.
    The Command design pattern is applied here to encapsulate the execution of an action.
    
 *Design Pattern: Command
 
*/
// Abstract base class for all commands with a pure virtual execute method.
class Command
{
public:
    virtual void execute() = 0; // Pure virtual function for executing the command.
    virtual ~Command() {} // Virtual destructor.
};

#endif
