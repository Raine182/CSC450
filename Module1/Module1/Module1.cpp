// Module1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    string firstName = "Jonathon";
    string lastName = "Morant";
    string homeStreet = "6017 Homefront Avenue";
    string homeCity = "Valintia";
    int zipCode = 99999;

    cout << "Citizen information:" << endl
        << firstName << " " << lastName << endl
        << "Address: " << homeStreet << ", " << homeCity << endl
        << "Zipcode: " << zipCode << endl;

    return 0;
}