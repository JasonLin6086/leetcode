#include <iostream>
#include <vector>
#include <algorithm>
//#include <math.h>
//#include <queue>
//#include <deque>
//#include <stack>
//#include <unordered_map>
//#include <set>
//#include <string>
//#include <unordered_set>
//#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> result;
        if (size < 4) return result;
        sort(nums.begin(), nums.end());
        for (int i=0; i<size-3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[size-3] + nums[size-2] + nums[size-1] < target) continue;
            for (int j=i+1; j<size-2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                if (nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if (nums[i] + nums[j] + nums[size-2] + nums[size-1] < target) continue;
                int left = j+1, right = size-1;
                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] > target) right --;
                    else if (nums[i] + nums[j] + nums[left] + nums[right] < target) left ++;
                    else {
                        result.push_back(vector<int>({nums[i], nums[j], nums[left], nums[right]}));
                        while (nums[left] == nums[left-1] && left < right) left ++;
                        right --;
                        while (nums[right] == nums[right+1] && left < right) right --;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    int myints[] = {1, 0, -1, 0, -2, 2};
    vector<int> input (myints, myints + sizeof(myints) / sizeof(int));
    vector<vector<int>> result = s.fourSum(input, 0);
    for (unsigned int i=0; i<result.size(); i++) {
        for (unsigned int j=0; j<result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
