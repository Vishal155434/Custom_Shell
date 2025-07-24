#ifndef SHELL_HPP
#define SHELL_HPP
#include<vector>
#include<string>

// The Shell class manages the prompt, input and command execution
class Shell{
    public:
        void run(); // Entry point for shell loop
         std::vector<std::string> history; //Stores history
        
        void loadHistory(); //loads from the file 
        void saveToHistoryFile(const std::string& cmd); //saves to file
    private:
        void displayPrompt();  // Shows "MyShell$" prompt
        std::string getInput(); //Read input from user
        void executeCommand(const std::string& input); // Execute the input command
       
};


#endif