// Problem Link: https://leetcode.com/problems/middle-of-the-linked-list/
// Time Complexity: O(n)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        return slow;
    }
};