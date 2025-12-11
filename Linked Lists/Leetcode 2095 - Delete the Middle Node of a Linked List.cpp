// Problem Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Time Complexity: O(n)

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
    ListNode* deleteMiddle(ListNode* start) {
        if(!start || !start -> next) return nullptr;

        ListNode* slow = start;
        ListNode* fast = start;
        ListNode* prev = nullptr;

        while(fast && fast -> next) {
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }
        prev -> next = slow -> next;
        delete slow;

        return start;
    }
};