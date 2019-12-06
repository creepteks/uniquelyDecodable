#include <iostream>
#include <iomanip>
using namespace std;

void printUsage();
void printSeperator(int);
void printEmptySpace(int);
void printLicence();
void printAskForCodeWords();

void printUsage()
{
    printSeperator(1);
    printLicence();
    printSeperator(1);

    cout << "enter the code words to determine if it is uniquely decodable" << endl;
    cout << "start by entering code words one by one without any space character" << endl;
    printEmptySpace(1);
    cout << "when you're finished entering code words, just press Enter" << endl;
    printEmptySpace(1);
}

void printAskForCodeWords()
{
    printSeperator(1);
    cout << "enter your code (enter nothing and press ENTER if you're done)" << endl;
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
