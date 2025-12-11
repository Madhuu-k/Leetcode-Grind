// Problem Link: https://leetcode.com/problems/palindrome-linked-list/
// Time Complexity: O(n)

class Solution {
public:
    bool isPalindrome(ListNode* start) {
        if(!start || !start -> next) return true;

        ListNode* fast = start;
        ListNode* slow = start;

        while(fast -> next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* prev = nullptr;
        ListNode* temp = slow -> next;
        ListNode* next = nullptr;

        while(temp) {
            next = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = next;
        }

        ListNode* p1 = start;
        ListNode* p2 = prev;

        while(p2) {
            if(p1 -> val != p2 -> val) return false;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }

        return  true;
    }
};