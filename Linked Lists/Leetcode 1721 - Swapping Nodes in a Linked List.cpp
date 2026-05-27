// Time Complexity: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// Problem Link: O(n)

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
    ListNode* swapNodes(ListNode* start, int k) {

        ListNode* slow = start;
        ListNode* fast = start;

        ListNode* firstK = nullptr;
        for(int i = 1; i < k; i++) fast = fast -> next;
        firstK = fast;

        while(fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }

        swap(firstK -> val, slow -> val);

        return start;
    }
};