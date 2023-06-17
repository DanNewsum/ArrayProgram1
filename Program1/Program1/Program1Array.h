#include <iostream>
#include <fstream>
#include <string>


class ReadAndEdit {
public:
    // This function reads a file, extracting the integers, and adds them to the array
    void readfile(std::string fileName);
    // This function prompts the user to input a number, and checks if it exists in the array
    void checkForNumber();
    // This function prompts the user to input an index and a new value, and replaces the old value at the given index with the new value
    void modifyValue();
    // This function prompts the user to input a new value, and adds it to the end of the array
    void addValue();
    // This function prompts the user to input an index, and either sets the value at that index to 0 or removes it from the array, shifting all later values down
    void remove();

private:
    // The array to store numbers. It is initialized to 0
    int numArray[150] = { 0 };
    // The current index to add a new number to the array
    int index = 0;
};
