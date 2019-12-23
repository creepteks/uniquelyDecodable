#include "decodable.hpp"
#include "typeDefs.hpp"
#include <assert.h>

#define ASSERT_WITH_MESSAGE(condition, message) \
    do                                          \
    {                                           \
        if (!(condition))                       \
        {                                       \
            printf((message));                  \
        }                                       \
        assert((condition));                    \
    } while (false)

void senarioI();
void senarioII();
void senarioIII();


int main()
{
    // check decodability
    senarioI();
    // senarioII();
    
    // check undecodability
    // senarioIII();
    return 0;
}

void senarioI()
{
    // senario I : the last column is a duplicate of the previous to the last column
    MAP map;
    STRING_VECTOR vec1, vec2, vec3, vec4;
    vec1.push_back("c"); vec1.push_back("b"); vec1.push_back("a");
    vec2.push_back("f"); vec2.push_back("d"); vec2.push_back("e");
    vec3.push_back("i"); vec3.push_back("g"); vec3.push_back("h");
    vec4.push_back("b"); vec4.push_back("a"); vec4.push_back("c");
    map = doMapInsertion(map, "s0", vec1);
    map = doMapInsertion(map, "s1", vec2);
    map = doMapInsertion(map, "s2", vec3);
    map = doMapInsertion(map, "s3", vec4);
    ASSERT_WITH_MESSAGE(isDecodable(map), "senario I: failed");
    cout << "senario I: passed; code is detactable" << endl;
}

void senarioII()
{
    // the last column is empty
    MAP map;
    STRING_VECTOR vec1, vec2;
    vec1.push_back("something");
    map = doMapInsertion(map, "s0", vec1);
    map = doMapInsertion(map, "s1", vec2);
    ASSERT_WITH_MESSAGE(isDecodable(map), "senario II: failed");
    cout << "senario II: passed; code is detactable" << endl;
}

void senarioIII()
{
    MAP map;
    STRING_VECTOR vec1, vec2, vec3;
        
    vec1.push_back("a"); vec1.push_back("b"); vec1.push_back("c");
    vec2.push_back("d"); vec2.push_back("d"); vec2.push_back("e");
    vec2.push_back("a");

    map = doMapInsertion(map, "s0", vec1);
    map = doMapInsertion(map, "s1", vec2);
    map = doMapInsertion(map, "s2", vec3);

    ASSERT_WITH_MESSAGE(isUndecodable(map), "senario III: failed");
    cout << "senario III: passed; code is undetactable";

}