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
        int count = 0;
        ListNode* dummy = start;
        while(dummy != nullptr && count < k){
            dummy = dummy -> next;
            count++;
        }

        if(count < k) return start;
        //Reverse the list
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        ListNode* temp = start;
        count = 0;
        while(temp != nullptr && count < k){
            nextNode = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = nextNode;
            count++;
        }

        if(nextNode) start -> next = reverseKGroup(nextNode, k);
        return prev;
    }
};