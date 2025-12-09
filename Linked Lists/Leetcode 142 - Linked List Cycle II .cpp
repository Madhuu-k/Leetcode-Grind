// Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Time Complexity: O(n)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *start) {
        if(!start) return nullptr;
        ListNode* slow = start;
        ListNode* fast = start;

        do {
            if(!fast || !fast -> next) return nullptr;
            slow = slow -> next;
            fast = fast -> next -> next;
        } while(slow != fast);

        slow = start;
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow;
    }
};