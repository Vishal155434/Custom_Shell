#include "../include/shell.hpp"
#include<iostream>
int main(){
    
    //Create a Shell object and run it
    Shell myShell;
    myShell.loadHistory();
    myShell.run(); // Start the input-processing loop
    return 0;
}