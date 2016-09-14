/*
 * solution.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: jason
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> rs;

        int i = 1, j, k;

        while (true)
        {
            // append as many zeroes as possible to the previous number
            for(k = 0; i*pow(10,k) <= n; ++k) rs.push_back(i*pow(10,k));

            // count continuously until we reach a number that ends with consecutive '9's
            for(j = rs.back()+1; j <= n && (j % 10) != 0; ++j) rs.push_back(j);

            // backtrace
            if(j % 10 == 0)
            {
                j--;
            }
            else
            {
                j /= 10;
            }

            // find the last non-'9' digit
            while(j % 10 == 9) j /= 10;

            // start a new sub-sequence
            i = j+1;

            if(rs.size() >= n) break;
        }

        return rs;
    }
};

int main()
{
    Solution s;
    vector<int> result = s.lexicalOrder(123);
    return 0;
}

