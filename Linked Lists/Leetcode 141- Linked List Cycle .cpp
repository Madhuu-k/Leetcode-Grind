// Problem Link: https://leetcode.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *start) {
        ListNode* slow = start;
        ListNode* fast = start;

        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) return true;
        }
        return false;
    }
};