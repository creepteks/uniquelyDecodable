#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

// func prototypes
map<string, vector<string>> step_I(map<string, vector<string>, vector<string>);
vector<string> findMatch(vector<string> from, vector<string> in);

// test functions
void testInput(vector<string>);

// test func implementations
void testInput(vector<string> chars)
{
    for (vector<string>::iterator it = chars.begin(); it != chars.end(); ++it)
    {
        cout << *it << endl;
    }
}