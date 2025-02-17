// Module5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void appendToFile(const string& filename, const string& userInput) {
    ofstream outfile(filename, ios::app);
    if (!outfile) {
        cerr << "Error opening file for appending." << endl;
        return;
    }
    outfile << userInput << endl;
    outfile.close();
}

void reverseFile(const string& inputFilename, const string& outputFilename) {
    ifstream infile(inputFilename);
    if (!infile) {
        cerr << "Error opening input file." << endl;
        return;
    }
    vector<char> contents((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());
    infile.close();

    reverse(contents.begin(), contents.end());

    ofstream outfile(outputFilename);
    if (!outfile) {
        cerr << "Error opening output file." << endl;
        return;
    }
    for (char c : contents) {
        outfile << c;
    }
    outfile.close();
}

int main() {
    string filename = "CSC450_CT5_mod5.txt";
    string reverseFilename = "Reverse_CSC450_CT5_mod5.txt";
    string userInput;

    cout << "Enter the text to append to the file: ";
    getline(cin, userInput);

    appendToFile(filename, userInput);
    reverseFile(filename, reverseFilename);

    cout << "User input has been appended to " << filename << " and reversed content is stored in " << reverseFilename << "." << endl;

    return 0;
}