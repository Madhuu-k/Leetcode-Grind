// Problem Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
// Time Complexity: O(1)

class Solution {
public:
    void deleteNode(ListNode* temp) {
        temp -> val = temp -> next -> val;
        ListNode* temp2 = temp -> next;
        temp -> next = temp -> next -> next;
        delete temp2;
    }
};