// Module2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>

using namespace std;

int main()
{
    string firstWord;
    string secondWord;
    string concatenate;

    for (int i = 0; i < 3; ++i) {
        cout << endl << "Type First word 3 times:";
        cin >> firstWord;

        cout << endl << "Type Second word 3 times:";
        cin >> secondWord;

        concatenate = firstWord + secondWord;
        cout << endl << "This results in the words: " << endl << endl << concatenate << endl << endl;

    }

    return 0;
}