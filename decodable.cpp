#include "decodable.hpp"
#include "input.hpp"
#include "printer.hpp"




int main()
{
    map<string, vector<string>> table;

    printUsage();

    auto res = readInput();

//  Debug Input  
    // testInput(res);
//  end Debug
        
    step_I(&table, res); // creating S0 table

    
    return 0;
}

// function implementation
vector<map<string, vector<string>>> step_I(map<string, vector<string>>* table, vector<string> words)
{
    table->insert(pair<string, vector<string>>("s0", words));
}










