/*
 * solution.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: jason
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        sort(nums.begin(), nums.end());
        int maxLen = 1, maxIndx = 0;
        vector<pair<int, int>> temp(nums.size(), make_pair(1, -1));
        for (int i = 1; i < nums.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (nums[i] % nums[j] == 0 && temp[i].first < temp[j].first + 1) {
                    temp[i].first = temp[j].first + 1;
                    temp[i].second = j;
                    if (maxLen < temp[i].first) {
                        maxLen = temp[i].first;
                        maxIndx = i;
                    }
                }
        vector<int> out;
        for ( ; maxIndx != -1; maxIndx = temp[maxIndx].second) out.push_back(nums[maxIndx]);
        return out;
    }
};

int main()
{
    Solution s;
    vector<int> input({1,2,7,8,25});
    vector<int> output = s.largestDivisibleSubset(input);
    for (int i=0; i<output.size(); i++) {
        cout<<output[i]<<":";
    }
    cout<<endl;
    return 0;
}




