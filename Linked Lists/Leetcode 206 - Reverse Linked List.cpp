// Problem Link: https://leetcode.com/problems/reverse-linked-list/
// Time complexity: O(n)

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
    ListNode* reverseList(ListNode* start) {
        ListNode* prev = nullptr;
        ListNode* temp = start;
        ListNode* next = nullptr;

        while(temp != nullptr){
            next = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
};