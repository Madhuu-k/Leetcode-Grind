// Problem Link: https://leetcode.com/problems/longest-word-in-dictionary/
// Time Complexity: O(N*L)

struct Trie{
    Trie* children[26];
    bool isEnd;
    Trie(){
        isEnd = false;
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution {
    Trie* root;
    string ans;

    void insert(string word){
        Trie* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node -> children[idx] == nullptr) node -> children[idx] = new Trie();
            node = node -> children[idx];
        }
        node -> isEnd = true;
    }

    void dfs(Trie* node, string& path){
        if(node != root && !node -> isEnd) return;
        if(path.size() > ans.size() || (path.size() == ans.size() && path < ans)) ans = path;
        for(int i = 0; i < 26; i++){
            if(node -> children[i] != nullptr){
                path.push_back('a' + i);
                dfs(node -> children[i], path);
                path.pop_back();
            }
        }
    }
public:
    string longestWord(vector<string>& words) {
        root = new Trie();
        for(string& w : words) insert(w);
        string path = "";
        dfs(root, path);
        return ans;
    }
};