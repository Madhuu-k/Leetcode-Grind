// Problem Link: https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* start, int m, int n) {
        if (!start || m == n) return start;

        ListNode dummy(0);
        dummy.next = start;
        ListNode* prev = &dummy;

        // move to m-1 ListNode
        for (int i = 1; i < m; i++) prev = prev -> next;

        ListNode* temp = prev -> next;
        ListNode* next = nullptr;

        // reverse (n-m+1) nodes
        for (int i = 0; i < n - m; i++) {
            next = temp -> next;
            temp -> next = next -> next;
            next -> next = prev -> next;
            prev -> next = next;
        }
        return dummy.next;
    }
};