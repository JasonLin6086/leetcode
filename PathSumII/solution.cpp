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

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};

int main() {
    Solution s;
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n11 = new TreeNode(11);
    TreeNode *n6 = new TreeNode(6);
    n3->left = n11;
    n4->right = n6;
    n5->left = n4;
    n5->right = n3;
    vector<vector<int>> result = s.pathSum(n5, 19);
    for (unsigned int i=0; i<result.size(); i++) {
        for (unsigned int j=0; j<result[i].size(); j++) {
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
