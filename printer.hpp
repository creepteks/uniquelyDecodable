#include <iostream>
#include <iomanip>
using namespace std;

void printUsage();
void printSeperator(int);
void printEmptySpace(int);
void printLicence();

void printUsage()
{
    printSeperator(1);
    printLicence();
    printSeperator(1);

    cout << "enter the code words to determine if it is uniquely decodable" << endl;
    cout << "start by entering code words one by one without any space character" << endl;
    
    // printEmptySpace(1);
    // printSeperator(1);
}

void printSeperator(int lines)
{
    for (size_t i = 0; i < lines; i++)
    {
        cout << std::setfill('_') << std::setw(30);
        cout << "" << endl;
        printEmptySpace(1);
    }
}

void printLicence()
{
    cout << "coded by neo under MIT licence" << endl;
}

void printEmptySpace(int lines)
{
    for (size_t i = 0; i < lines; i++)
    {
        cout << endl;
    }
}
