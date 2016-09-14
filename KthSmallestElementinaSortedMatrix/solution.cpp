/*
 * solution.cpp
 *
 *  Created on: Aug 31, 2016
 *      Author: jason
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int size = matrix.size(), l = matrix[0][0], r = matrix[size-1][size-1];
        int smaller = 0;
        while(l < r)
        {
            smaller = 0;
            int m = l+((r-l)>>1);
            for(int i = 0; i < size; ++i) {
                auto tmp1 = upper_bound(matrix[i].begin(), matrix[i].end(), m);
                auto tmp2 = matrix[i].begin();
                smaller += tmp1 - tmp2;
            }
            smaller<k? l=m+1 : r=m;
        }
        return r;
    }
};

int main()
{
    vector<vector<int>> input ({{1,5,9},{10,11,13},{12,13,15}});
    Solution s;
    cout<<s.kthSmallest(input, 3)<<endl;
    return 0;
}



