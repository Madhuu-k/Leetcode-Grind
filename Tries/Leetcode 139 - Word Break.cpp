// Problem Link: https://leetcode.com/problems/word-break/
// Time Complexity: O(K × L + N × L)

class Solution {
    struct TrieNode{
        bool isEnd;
        TrieNode* children[26];
        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    void insert(TrieNode* root, const string& word){
        TrieNode* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node -> children[idx] == nullptr) node -> children[idx] = new TrieNode();
            node = node -> children[idx];
        }
        node -> isEnd = true;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for(auto& w : wordDict) insert(root, w);
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 0; i < n; i++){
            if(!dp[i]) continue;
            TrieNode* node = root;
            for(int j = i; j < n; j++){
                int idx = s[j] - 'a';
                if(!node -> children[idx]) break;
                node = node -> children[idx];
                if(node -> isEnd) dp[j + 1] = true;
            }
        }
        return dp[n];
    }
};