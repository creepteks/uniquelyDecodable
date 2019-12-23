#include "decodable.hpp"
#include "input.hpp"
#include "typeDefs.hpp"

int main()
{
    map<string, vector<string>> *table = new map<string, vector<string>>();

    printUsage();

    vector<string> codeWords = readInput();

    // Step I: creating S0 column from the words we gonna call A0s
    doMapInsertion(table, "s0", codeWords);

    // Step II: creating S1 by comparing S0 elements againts each other
    vector<string> a1_suffixes = findSuffixes(*table, "s0", "s0");
    doMapInsertion(table, "s1", a1_suffixes);

    // Step III and IV: creating Sn by comparing Sn-1 and S0; then check decodability of the code
    while (true)
    {
        if (isUndecodable(table))
        {
            cout << "code is undecodable" << endl;
            break;
        }

        if (isDecodable(table)) 
        {
            cout << "code is decodable" << endl;
            break;
        }

        stringstream s;
        s << table->size();
        string lastColKey = "s" + s.str();

        auto a2_suffixes_1 = findSuffixes(*table, "s0", (--table->end())->first);
        auto a2_suffixes_2 = findSuffixes(*table,  (--table->end())->first, "s0");
        doMapInsertion(table, lastColKey, a2_suffixes_1);
        doMapInsertion(table, lastColKey, a2_suffixes_2);
    }
    
    delete(table);
    auto res = table->find("s0");
    return 0;
}
