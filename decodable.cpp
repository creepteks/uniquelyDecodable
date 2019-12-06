#include "decodable.hpp"
#include "input.hpp"

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

    // Step III and IV: creating Sn by comparing Sn-1 and S0; then check decodability of the code
    while (true)
    {
        if (isDecodable(map)) 
        {
            cout << "code is decodable" << endl;
            break;
        }

        if (isUndecodable(map))
        {
            cout << "code is undecodable" << endl;
            break;
        }

        stringstream s;
        s << map.size();
        string lastColKey = "s" + s.str();

        auto a2_suffixes_1 = findSuffixes(map, "s0", (--map.end())->first);
        auto a2_suffixes_2 = findSuffixes(map,  (--map.end())->first, "s0");
        map = doMapInsertion(map, lastColKey, a2_suffixes_1);
        map = doMapInsertion(map, lastColKey, a2_suffixes_2);
    }
    
    return 0;
}
