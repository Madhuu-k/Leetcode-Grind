// Problem Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/submissions/1736798807/
// Time Complexity: O(N)

class Solution {
    struct Node{
        Node* next[2];
        Node(): next{nullptr, nullptr} {}
    };

    void insert(Node* root, int x){
        Node* curr = root;
        for(int b = 31; b >= 0; b--){
            int bit = (x >> b) & 1;
            if(curr -> next[bit] == nullptr) curr -> next[bit] = new Node();
            curr = curr -> next[bit];
        }
    }

    int bestXOR(Node* root, int x){
        Node* curr = root;
        int ans = 0;
        for(int b = 31; b >= 0; b--){
            int bit = (x >> b) & 1;
            int want = bit ^ 1;
            if(curr -> next[want]){
                ans |= (1 << b);
                curr = curr -> next[want];
            }
            else curr = curr -> next[bit];
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        Node* root = new Node();
        insert(root, nums[0]);
        int best = 0;
        for(int i = 1; i < nums.size(); i++){
            best = max(best, bestXOR(root, nums[i]));
            insert(root, nums[i]);
        }
        return best;
    }
};