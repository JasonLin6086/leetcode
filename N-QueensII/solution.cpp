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
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> mark(n);
        vector<int> cols(n, -1);
        for (int i = 0; i < n; i++)
        {
            cols[0] = i;
            mark[i] = true;
            helper(1, n, count, mark, cols);
            cols[0] = -1;
            mark[i] = false;
        }
        return count;
    }
private:
    void helper(int s, int n, int& count, vector<bool>& mark, vector<int>& cols) {
        if (s == n) {
            count++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!mark[i]) {
                bool mark2 = true;
                for (int k = 0; k < s; k++) {
                    if (abs(s - k) == abs(i - cols[k])) {
                        mark2 = false;
                        break;
                    }
                }
                if (mark2) {
                    cols[s] = i;
                    mark[i] = true;
                    helper(s + 1, n, count, mark, cols);
                    cols[s] = -1;
                    mark[i] = false;
                }
            }
        }
    }
};

int main() {
    Solution s;
    cout<<s.totalNQueens(10)<<endl;
    return 0;
}
