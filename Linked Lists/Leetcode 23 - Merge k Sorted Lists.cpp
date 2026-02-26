// Problem Link: https://leetcode.com/problems/merge-k-sorted-lists/
// Time Complexity: O(N Log K)

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
    ListNode* mergedLists(ListNode* l1, ListNode* l2){
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode* newList = new ListNode(-1);
        ListNode* temp = newList;
        while(l1 && l2){
            if(l1 -> val < l2 -> val){
                temp -> next = l1;
                l1 = l1 -> next;
            }
            else{
                temp -> next = l2;
                l2 = l2 -> next;
            }
            temp = temp -> next;
        }
        if(l1) temp -> next = l1;
        else temp -> next = l2;

        return newList -> next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        while(lists.size() > 1){
            vector<ListNode*> merged;
            for(int i = 0; i < lists.size(); i+=2){
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1 < lists.size()) ? lists[i + 1] : nullptr;
                merged.push_back(mergedLists(l1, l2));
            }
            lists = merged;
        }
        return lists[0];
    }
};