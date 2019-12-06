#include "decodable.hpp"
#include "input.hpp"
#include "printer.hpp"

int main()
{
    map<string, vector<string>> map;

    printUsage();

    auto res = readInput();

    // Step I: creating S0 column from the words we gonna call A0s
    map = doMapInsertion(map, "s0", res);

    // Step II: creating S1 by comparing S0 elements againts each other
    vector<string> a1_suffixes = findSuffixes(map, "s0", "s0");
    map = doMapInsertion(map, "s1", a1_suffixes);
    while (true)
    {
        
    }
    
    return 0;
}
