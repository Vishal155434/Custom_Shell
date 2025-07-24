#include "../include/shell.hpp"
#include <iostream>
#include <sstream> //for splitting command into tokens
#include <windows.h>
#include <vector>
#include <cstring>
#include <fstream>




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
    std::istringstream iss(input);
    std::string command;
    iss >> command;
    history.push_back(input);
    saveToHistoryFile(input);

    if (command == "exit"){
        std::cout<< "Exiting shell ...\n";
        exit(0);
    }
    else if (command == "clear"){
        system("cls");
        return;
    }
    else if (command == "cd"){
        std::string path = input.substr(3);
        iss >> path;
        char buffer[MAX_PATH];
        GetCurrentDirectoryA(MAX_PATH, buffer);
        std::cout<<"We are at : "<< buffer<<std::endl;
        if (!SetCurrentDirectoryA(path.c_str())){
            std::cerr<<"cd failed \n";
        }
        return;
    }
    else if (command == "echo"){
        std::string rest;
        getline(iss, rest);
        std::cout<<rest<<std::endl;
        return;
    }
    else if (command == "help"){
        std::cout<<"Built-in commands :\n";
        std::cout<<"cd [dir], exit, help, clear, history, echo ,pwd \n";      
    }
    else if (command == "pwd"){
        char buffer[MAX_PATH];
        GetCurrentDirectoryA(MAX_PATH, buffer);
        std::cout<< buffer<<std::endl;
    }
    else if (command == "history"){
        for (int i = 0; i<history.size(); ++i){
            std::cout<<i + 1 << " "<< history[i]<<std::endl;
        }
    }
    else{
    system(input.c_str());
    }
   
}

void Shell::loadHistory(){
    std::ifstream file("history.txt");
    std::string line;
    while (std::getline(file, line)){
        history.push_back(line); //Add each line to history vector

    }
    file.close();
}

void Shell::saveToHistoryFile(const std::string& cmd){
    std::ofstream file("history.txt",std::ios::app);
    file <<cmd <<std::endl;
    file.close();
}



