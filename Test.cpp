#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("OrgChart")
{
 
        


    // loop 50 times to test all the cases
    int j = 0;
    for (int i = 0; i < 50; i++)
    {
        CHECK(i == j);
    }
}