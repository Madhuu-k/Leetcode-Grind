// Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
// Time Complexity: O(L)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* start, int n) {
        ListNode* temp = new ListNode(-1);
        temp -> next = start;

        ListNode* slow = temp;
        ListNode* fast = temp;

        for(int i = 0; i < n; i++) fast = fast -> next;
        while(fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next;
        }

        ListNode* nodeToDelete = slow -> next;
        slow -> next = nodeToDelete -> next;
        delete nodeToDelete;

        return temp -> next;
    }
};
