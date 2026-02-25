// Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/1694016975/
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
    ListNode* reverseKGroup(ListNode* start, int k) {
        if(!start || k == 1) return start;
        ListNode* dummy = new ListNode(-1);
        dummy -> next = start;
        ListNode* groupPrev = dummy; // Initital starting of new List

        while(true){
            ListNode* kth = groupPrev;
            for(int i = 0; i < k && kth != nullptr; i++) kth = kth -> next;
            if(kth == nullptr) break;
            ListNode* groupNext = kth -> next; // Points to next head (prev - more like nullptr)

            // Reversr the list till Kth
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev -> next;
            while(curr != groupNext){
                ListNode* temp = curr -> next;
                curr -> next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = groupPrev -> next;
            groupPrev -> next = kth;
            groupPrev = temp;
        }
        return dummy -> next;
    }
};