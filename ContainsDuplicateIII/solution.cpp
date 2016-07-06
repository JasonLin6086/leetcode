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

bool cmpptr(int *a, int *b){
    return *a < *b;
}
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(0 == k) return false;

        const int N = nums.size();
        vector<int*> numptrs(N);
        for(int i = 0; i < N; i++){
           numptrs[i] = &nums[i];
        }
        sort(numptrs.begin(), numptrs.end(), cmpptr);

        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                 //nums[i] and nums[j] is at most t
                if((*numptrs[j]) > (*numptrs[i]) + t) break;
                //the difference between i and j is at most k
                if(abs(numptrs[j] - numptrs[i]) <= k) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    int myints[] = {1};
    vector<int> input (myints, myints + sizeof(myints) / sizeof(int));
    bool result = s.containsNearbyAlmostDuplicate(input, 1, 1);
    cout<<result<<endl;
    return 0;
}
