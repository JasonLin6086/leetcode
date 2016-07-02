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
     TreeNode *left = NULL;
     TreeNode *right = NULL;
     TreeNode(int x, TreeNode * left, TreeNode * right) {
         this->val = x;
         this->left = left;
         this->right = right;
     }
 };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //if (root!=NULL) cout<<"root="<<root->val<<endl;
        if (!root || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        /*
        if (left==NULL) cout<<"NULL"<<endl;
        else            cout<<left->val<<endl;
        if (right==NULL) cout<<"NULL"<<endl;
        else            cout<<right->val<<endl;
        */
        return !left ? right : !right ? left : root;
    }
};

int main()
{
    Solution s;
    TreeNode * n8 = new TreeNode(8, NULL, NULL);
    TreeNode * n4 = new TreeNode(4, n8, NULL);
    TreeNode * n5 = new TreeNode(5, NULL, NULL);
    TreeNode * n6 = new TreeNode(6, NULL, NULL);
    TreeNode * n7 = new TreeNode(7, NULL, NULL);
    TreeNode * n2 = new TreeNode(2, n4, n5);
    TreeNode * n3 = new TreeNode(3, n6, n7);
    TreeNode * n1 = new TreeNode(1, n2, n3);

    TreeNode * result;
    result = s.lowestCommonAncestor(n1, n8, n7);
    cout<<result->val<<endl;
    result = s.lowestCommonAncestor(n1, n4, n5);
    cout<<result->val<<endl;
    result = s.lowestCommonAncestor(n1, n5, n8);
    cout<<result->val<<endl;
    return 0;
}
