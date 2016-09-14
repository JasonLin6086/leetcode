/*
 * solution.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: jason
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution {
public:
    Node* Merge (Node* head1, Node* head2) {
        Node* dummy = new Node(0);
        Node* current = dummy;
        while (head1 && head2) {
            if (head1->data < head2->data) {
                current->next = head1;
                head1 = head1->next;
            } else {
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }
        if (head1) {
            current->next = head1;
        }
        if (head2) {
            current->next = head2;
        }
        return dummy->next;
    }
};

int main()
{
    Node* l1 = new Node(0);
    l1->next = new Node(2);
    l1->next->next = new Node(4);
    Node* l2 = new Node(2);
    l2->next = new Node(3);
    l2->next->next = new Node(5);
    Solution s;
    Node * result = s.Merge(l1, l2);
    while (result != NULL) {
        cout<<result->data<<(result->next ? "," : "");
        result = result->next;
    }
    cout<<endl;
}



