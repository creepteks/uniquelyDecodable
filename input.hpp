// neo, Friday December 6, 2019; 1:07 AM

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<string> readInput()
{
    vector<string> wordsList;
    string word, word_trimmed;

    while (getline(cin, word) && !word.empty())
    {
        stringstream trimmer(word);
        getline(trimmer, word_trimmed, ' ');
        wordsList.push_back(word_trimmed);
    }    
    return wordsList;
}