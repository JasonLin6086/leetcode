/*
 * solution.cpp
 *
 *  Created on: Sep 2, 2016
 *      Author: jason
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        int mt, ms;
        rob(root, mt, ms);
        return max(mt, ms);
    }

private:
    void rob(TreeNode* node, int& mt, int& ms)
    {
        mt = ms = 0;
        if (!node) return;

        int mtl, mtr, msl, msr;
        rob(node->left, mtl, msl);
        rob(node->right, mtr, msr);

        mt = msl + msr + node->val;
        ms = max(mtl, msl) + max(mtr, msr);
        return;
    }
};

int main()
{
    Solution s;
    TreeNode *n0 = new TreeNode(3);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(1);
    n0->left = n1;
    n0->right = n2;
    n1->right = n3;
    n2->right = n4;
    cout<<s.rob(n0)<<endl;
    return 0;
}

