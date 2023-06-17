// Program1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Dan Newsum 
//Array program. Assignment 1

#include "Program1Array.h"
#include <string>
int main()
{
    std::string fileName = "file1.txt";
    int pick = 0;
    bool running = true;
    ReadAndEdit firstFileRead;
    firstFileRead.readfile(fileName);
    while (running == true) {
        std::cout << "\n";
        std::cout << "What would you like to do? \n1. For check for number. \n2. For modify the array. \n3. For adding to the array \n4. For replacing or making 0.\n5. To quit";
        std::cout << "\n";
        std::cin >> pick;
        if (pick == 1)
        {
            firstFileRead.checkForNumber();
            
        }
        else if (pick == 2)
        {
            firstFileRead.modifyValue();
        }
        else if (pick == 3)
        {
            firstFileRead.addValue();
        }
        else if (pick == 4)
        {
            firstFileRead.remove();
        }
        else if (pick == 5)
        {
            running = false;
            
        }
        else
        {
            std::cout << "Please pick a valid option.";
        }

    }
}

