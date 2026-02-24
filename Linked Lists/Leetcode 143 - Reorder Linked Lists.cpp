// Problem Link: https://leetcode.com/problems/reorder-list/
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
    void reorderList(ListNode* start) {
        if(start == nullptr) return;
        ListNode* temp = start;
        ListNode* slow = temp;
        ListNode* fast = temp;

        // 1. Find the middle of list
        while(fast -> next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // 2. Reverse the list from slow -> next
        ListNode* second = slow -> next;
        slow -> next = nullptr;

        ListNode* prev = nullptr;
        while(second){
            ListNode* nextNode = second -> next;
            second -> next = prev;
            prev = second;
            second = nextNode;
        }

        // 3, Merge Both lists
        ListNode* first = start;
        second = prev;

        while(second){
            ListNode* firstNext = first -> next;
            ListNode* secondNext = second -> next;

            first -> next = second;
            second -> next = firstNext;

            first = firstNext;
            second = secondNext;
        }

    }
};
