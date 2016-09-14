#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition for binary tree with next pointer.
 */
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

class Solution {
public:
    void connect(TreeLinkNode *root) {
        /*
        while(root != NULL){
            TreeLinkNode* tempChild = new TreeLinkNode(0);
            TreeLinkNode* currentChild = tempChild;
            while(root != NULL){
                if(root->left != NULL) { currentChild = currentChild->next = root->left; }
                if(root->right != NULL) { currentChild = currentChild->next = root->right; }
                root = root->next;
            }
            root = tempChild->next;
        }
        */
        TreeLinkNode *now, *tail, *head;

        now = root;
        head = tail = NULL;
        while(now)
        {
            if (now->left)
                if (tail) tail = tail->next = now->left;
                else head = tail = now->left;
            if (now->right)
                if (tail) tail = tail->next = now->right;
                else head = tail = now->right;
            if(! (now = now->next)) {
                now = head;
                head = tail = NULL;
            }
        }
    }
};

int main() {
    Solution s;
    TreeLinkNode *n1 = new TreeLinkNode(1);
    TreeLinkNode *n2 = new TreeLinkNode(2);
    TreeLinkNode *n3 = new TreeLinkNode(3);
    TreeLinkNode *n4 = new TreeLinkNode(4);
    TreeLinkNode *n5 = new TreeLinkNode(5);
    TreeLinkNode *n6 = new TreeLinkNode(6);
    TreeLinkNode *n7 = new TreeLinkNode(7);
    n1->left = n2; n1->right = n3;
    n2->left = n4; n2->right = n5;
    n3->right = n7;
    s.connect(n1);
    return 0;
}
