// Module3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

using namespace std;

int main() {
    int var1;
    int var2;
    int var3;

    // Asking user to enter three input values
    cout << "Enter three integer values:" << endl;
    cin >> var1 >> var2 >> var3;

    // Creating integer pointers to dynamic memory
    int* ptr1 = new int;
    int* ptr2 = new int;
    int* ptr3 = new int;

    // Assigning the values to the pointers
    *ptr1 = var1;
    *ptr2 = var2;
    *ptr3 = var3;

    //Displaying the variables and pointers
    cout << "Values entered: " << var1 << ", " << var2
        << ", " << var3 << endl;

    cout << "Pointer values: " << *ptr1 << ", "
        << *ptr2 << ", " << *ptr3 << endl;

    // Freeing the allocated memory
    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}