#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Good case ")
{
 
     OrgChart org;
  
        CHECK_NOTHROW(org.add_root("root"));
        CHECK_NOTHROW(org.add_sub("root", "child1"));
        CHECK_NOTHROW(org.add_sub("child1", "grandchild1"));
        CHECK_NOTHROW(org.add_sub("grandchild1", "greatgrandchild1"));
        CHECK_NOTHROW(org.add_sub("root", "child2"));
        CHECK_NOTHROW(org.add_sub("child2", "grandchild2"));
        CHECK_NOTHROW(org.add_sub("grandchild2", "greatgrandchild2"));
        CHECK_NOTHROW(org.add_sub("root", "child3"));
        CHECK_NOTHROW(org.add_sub("child3", "grandchild3"));
        CHECK_NOTHROW(org.add_sub("grandchild3", "greatgrandchild3"));
        CHECK_NOTHROW(org.add_sub("root", "child4"));
        CHECK_NOTHROW(org.add_sub("child4", "grandchild4"));
        CHECK_NOTHROW(org.add_sub("grandchild4", "greatgrandchild4"));
        string token; 
        string forchild;  

        //  level order 
        int i = 0 ; 
        for (auto it = org.begin_level_order(); it != org.end_level_order(); it++) {
            if (i == 0 ){
                CHECK (*it == "root");
                i++;
                continue;
            }
            if (i <= 4){
            token = *it;
            forchild = "child"; 
            forchild += to_string(i);
            CHECK(token == forchild);
            printf("%s\n", token.c_str());
            i++;
            continue;
            }
            if (5 <= i && i < 8){
            token = *it;
            forchild = "grandchild"; 
            forchild += to_string(i%4);
            printf("%s\n", token.c_str());
            CHECK(token == forchild);
            i++; 
            continue;
            }
            if (9 <= i && i < 12){
            token = *it;
            forchild = "greatgrandchild";
            forchild += to_string(i%4+1);
            CHECK(token == forchild);
            i++; 
            continue;
            }
        

        
    }
    // check revese order
    vector<string> collect_to_reverse ; 
    collect_to_reverse.clear();
       for (auto it = org.begin_level_order(); it != org.end_level_order(); it++) {
            if (i == 0 ){
                CHECK (*it == "root");
                i++;
                continue;
            }
            if (i <= 4){
            token = *it;
            collect_to_reverse.push_back(token);
            forchild = "child"; 
            forchild += to_string(i);
            CHECK(token == forchild);
            printf("%s\n", token.c_str());
            i++;
            continue;
            }
            if (5 <= i && i < 8){
            token = *it;
            collect_to_reverse.push_back(token);
            forchild = "grandchild"; 
            forchild += to_string(i%4);
            printf("%s\n", token.c_str());
            CHECK(token == forchild);
            i++; 
            continue;
            }
            if (9 <= i && i < 12){
            token = *it;
            collect_to_reverse.push_back(token);
            forchild = "greatgrandchild";
            forchild += to_string(i%4+1);
            CHECK(token == forchild);
            i++; 
            continue;
            }
        
       }
        reverse(collect_to_reverse.begin(), collect_to_reverse.end());
        for (auto it = org.begin_reverse_order(); it != org.reverse_order(); it++) {
            CHECK (*it == collect_to_reverse.back()); // check if the reverse order is correct
            collect_to_reverse.pop_back(); // remove the last element from the vector
        }

    }
TEST_CASE("Bad cases"){

    OrgChart org; 
    CHECK_THROWS(org.add_sub("root", "child")); // still no root 
    CHECK_NOTHROW(org.add_root("root"));
    CHECK_NOTHROW(org.add_sub("root", "child"));
    CHECK_NOTHROW(org.add_sub("child", "grandchild"));
    CHECK_NOTHROW(org.add_sub("grandchild", "greatgrandchild"));
    CHECK_THROWS(org.add_sub("whatt", "cannot"));// no such parent
    CHECK_THROWS(org.add_sub("bishbash", "child")); // no such parent

}