#include "Program1Array.h"
#include "fstream"
#include "sstream"
#include "iostream"
#include "stdexcept"

// Function to read the file and store the numbers into the array
void ReadAndEdit::readfile(std::string FileName) {

    std::ifstream fileData; 
    std::string line;

    // Open the file
    fileData.open(FileName);

    // Read the file line by line. ',' is used as a delimiter
    while (std::getline(fileData, line, ',')) {
        std::stringstream ss(line); // Used to look at integers from the line
        int num;
        ss >> num; // Extract the integer

        // Check if there is still space in the array
        if (index < 150) {
            ReadAndEdit::numArray[index] = num; // Add the number to the array
            index++; // Move to the next position in the array
        }
    }
}

// Function to modify a value in the array
void ReadAndEdit::modifyValue() {
    int newVal = 0; // The new value
    int index = 0; // The index to be changed

    // Ask the user for the index and the new value
    std::cout << "What index value do you want to change? ";
    std::cin >> index;
    std::cout << "\n" << "What new value do you want? ";
    std::cin >> newVal;

    try
    {
        // Check if the index is valid
        if (index >= 0 && index < 150)
        {
            int oldNum = numArray[index]; // The old number
            numArray[index] = newVal; // Replace the old number with the new value
            // Print out the old and new values
            std::cout << "Old value at index " << index << " was " << oldNum << "\n";
            std::cout << "New value is " << newVal;
        }
        else
        {
            // Throw an exception if the index is invalid
            throw std::out_of_range("Invalid index. Index should be between 0 and 149.");

        }
    }
    catch (std::out_of_range& e)
    {
        
        std::cout << "Caught an exception: " << e.what() << '\n';
    }
}

// Function to add a new value to the array
void ReadAndEdit::addValue() {

    int newVal = 0; // The new value
    std::cout << "What value do you want to add? ";
    std::cin >> newVal;
    try
    {
        // Check if there is still space in the array
        if (index < 150) {
            numArray[index] = newVal; // Add the new value to the array
            index++; // Move to the next position in the array
        }
        else
        {
            // Throw an exception if the array is full
            throw std::out_of_range("Invalid. The array is full.");
        }
    }
    catch (const std::exception& error)
    {
        
        std::cout << "Caught an exception: " << error.what() << '\n';
    }

}

// Function to remove a value from the array
void ReadAndEdit::remove() {
    int place = 0; // The index to be removed
    std::cout << "what index do you want to remove or make 0? ";
    std::cin >> place;
    index = place;
    std::cout << "Select 1 to make 0 or select 2 to remove: ";
    int choice;
    std::cin >> choice;

    // Check if the index is valid
    if (index >= 0 && index < 150) {
        if (choice == 1) {
            numArray[index] = 0; // Replace with zero
        }
        else if (choice == 2) {
            // Shift all the values down by one position
            for (int i = index; i < this->index - 1; i++) {
                numArray[i] = numArray[i + 1];
            }
            numArray[this->index - 1] = 0; // Set the last number to zero
            this->index--; // Decrease the index
        }
    }
    else {
        std::cout << "Invalid index. Index should be between 0 and " << this->index - 1 << ".\n";
    }
}

// Function to check if a number exists in the array
void ReadAndEdit::checkForNumber() {
    std::string str;
    std::cout << "Enter a number to check for: ";
    std::cin >> str;
    std::cout << "\n";

    // Go through all the numbers in the array
    for (int i = 0; i < 150; i++)
    {
        // Check if the entered number is in the array
        if (stoi(str) == ReadAndEdit::numArray[i])
        {
            // Print out the position if the number is found
            std::cout << "The value " << str << " is in the array at position " << i;
        }
    }
}
