// Problem Link: https://leetcode.com/problems/copy-list-with-random-pointer/description/
// Time Complexity: O(n)

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* start) {
        if(start == nullptr) return nullptr;

        unordered_map<Node*, Node*> mp;
        Node* temp = start;

        while(temp != nullptr){
            mp[temp] = new Node(temp -> val);
            temp = temp -> next;
        }

        temp = start;

        while(temp != nullptr){
            mp[temp] -> next = mp[temp -> next];
            mp[temp] -> random = mp[temp -> random];
            temp = temp -> next;
        }
        return mp[start];
    }
};
