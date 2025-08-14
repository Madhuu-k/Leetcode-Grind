// Problem Link: https://leetcode.com/problems/search-suggestions-system/
// Time Complexity: O(N * Llogn)

struct Trie{
    Trie* children[26];
    bool isEnd;
    vector<string> top;

    Trie(){
        isEnd = false;
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }
};


class Solution {
public:
    Trie* root = new Trie();
    int K;
    void insert(string& word){
        Trie* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node -> children[idx] == nullptr) node -> children[idx] = new Trie();
            node = node -> children[idx];
            auto it = lower_bound(node->top.begin(), node->top.end(), word);
            node->top.insert(it, word);
            if((int)node -> top.size() > K) node -> top.pop_back();
        }
        node -> isEnd = true;
    }

    Trie* walk(string& prefix){
        Trie* node = root;
        for(char c : prefix){
            int idx = c - 'a';
            if(node -> children[idx] == nullptr) return nullptr;
            node = node -> children[idx];
        }
        return node;
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        K = 3;
        for(string& product : products) insert(product);
        vector<vector<string>> result;
        Trie* node = root;
        for(char c : searchWord){
            if(node != nullptr) node = node -> children[c - 'a'];
            if(node == nullptr) result.push_back({});
            else result.push_back(node -> top);
        }
        return result;
    }

};