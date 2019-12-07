#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

// func prototypes
map<string, vector<string>> doMapInsertion(map<string, vector<string>>, string, vector<string>);
vector<string> findSuffixes(map<string, vector<string>>, string list1, string list2);
bool foundMatch(map<string, vector<string>>);
bool isDecodable(map<string, vector<string>>);
bool isUndecodable(map<string, vector<string>>);

// func implementations
map<string, vector<string>> doMapInsertion(map<string, vector<string>> _map, string key, vector<string> entries)
{
    if (_map.find(key) == _map.end())
    {
        // the map do not contain the given key, so I have to add it even if the entries are empty
        _map.insert({key, entries}); // or _map.insert(pair<string, vector<string>> (key, entries))
        return _map;
    }

    // reaching here means the map already contains the key, so
    auto it = _map.find(key)->second;

    for (size_t i = 0; i < entries.size(); i++)
    {
        it.push_back(entries[i]);
    }
    _map.find(key)->second = it;
    return _map;
}

vector<string> findSuffixes (map<string, vector<string>> map, string list1, string list2)
{
    vector<string> foundSuffixes;
    // check if map contains the key for list1
    auto iterator_list1 = map.find(list1);
    if (iterator_list1 == map.end())
    {
        cerr << list1 << " is not a valid key or has not been added to the map" << endl;
        return foundSuffixes;
    } 

    // check if map containt the key for list2
    auto iterator_list2 = map.find(list2);
    if (iterator_list2 == map.end())
    {
        cerr << list2 << " is not a valid key or has not been added to the map" << endl;
        return foundSuffixes;
    }

    for (vector<string>::iterator it_i = iterator_list1->second.begin(); it_i != iterator_list1->second.end(); ++it_i)
    {
        for (vector<string>::iterator it_j = iterator_list2->second.begin(); it_j != iterator_list2->second.end(); ++it_j)
        {
            // the suffix of ai such that ai = aj + suffix, can only be found if length of aj is smaller than ai
            if (it_j->length() >= it_i->length())
                continue; // no suffix could be found, continuing with the next item on the vector

            // check if aj can be found inside ai
            string prefix = it_i->substr(0, it_j->length());
            if (prefix.compare(*it_j))
                continue; // no suffix will be found since ai is not equal to some aj + suffix

            string suff = it_i->substr(it_j->length(), it_i->length() - it_j->length());
            if (!suff.empty())
                foundSuffixes.push_back(suff);
        }
        
    }
    return foundSuffixes;
}

bool isDecodable(map<string, vector<string>> _map)
{
    // if the last comumn in the table is empty, the code is decodable
    map<string, vector<string>>::iterator lastCol = --_map.end();

    if (lastCol->second.size() <= 0)
        return true; // NOTE the code is detactable
    
    // if the last column is a copy of the previous to the last column, the code is decodable
    map<string, vector<string>>::iterator previousToLastCol = ----_map.end();
    std::sort(previousToLastCol->second.begin(), previousToLastCol->second.end());
    std::sort(lastCol->second.begin(), lastCol->second.end());
    // std::vector<string> v3;
    // std::set_intersection(previousToLastCol->second.begin(), previousToLastCol->second.end(), lastCol->second.begin(), lastCol->second.end(), std::back_inserter(v3));
    // if (v3 == previousToLastCol->second && v3 == lastCol->second)
    if (previousToLastCol->second == lastCol->second) 
    {
        return true; // NOTE the code is decodable
    }
    
    return false; // NOTE the code is not decodable
}

bool isUndecodable(map<string, vector<string>> _map)
{
    map<string, vector<string>>::iterator firstColIterator = _map.begin();
    map<string, vector<string>>::iterator lastColIterator = --_map.end();
    // iterating through items of the last column
    for (auto sn = lastColIterator->second.begin(); sn != lastColIterator->second.end(); sn++)
    {
        // iterating through items of the very first column
        for (auto s0 = firstColIterator->second.begin(); s0 != firstColIterator->second.end(); s0++)
        {
            if (*sn == *s0) 
            {
                // found a match between the first and the last column. NOTE the code is undecodable
                return true;
            }
        }
    }
    // I did not find a match, NOTE the code is decodable
    return false;
}
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