#ifndef SHELL_HPP
#define SHELL_HPP

#include<string>

// The Shell class manages the prompt, input and command execution
class Shell{
    public:
        void run(); // Entry point for shell loop
    private:
        void displayPrompt();  // Shows "MyShell$" prompt
        std::string getInput(); //Read input from user
        void executeCommand(const std::string& input); // Execute the input command
};


#endif