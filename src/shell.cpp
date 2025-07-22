#include "../include/shell.hpp"
#include <iostream>
#include <sstream> //for splitting command into tokens
#include <windows.h>
#include <vector>
#include <cstring>




// Main Shell Loop

void Shell::run(){
    while (true)
    {
        displayPrompt();  //1. Show shell

        std::string input = getInput(); //2. Get user input 

        if (input.empty()) continue; // 3. Ignore Empty input
        
        executeCommand(input);  //4. Process and run the command 
    }
    
}

// Print the shell prompt
void Shell::displayPrompt(){
    std::cout<< "MyShell$";
}

// Get a full line of input from the user

std::string Shell::getInput(){
    std::string input;
    std::getline(std::cin, input); // getline reads the entire line including spaces
    return input;
}

//Handle built-in or external commands
void Shell::executeCommand(const std::string& input){
    if (input == "exit"){
        std::cout<< "Exiting shell ...\n";
        exit(0);
    }
    if (input == "clear"){
        system("cls");
        return;
    }
    if (input.substr(0,3) == "cd"){
        std::string path = input.substr(3);
        if (!SetCurrentDirectoryA(path.c_str())){
            std::cerr<<"cd failed \n";
        }
        return;
    }
    system(input.c_str());
}



int main(){
    
    //Create a Shell object and run it
    Shell myShell;
    myShell.run(); // Start the input-processing loop
    return 0;
}