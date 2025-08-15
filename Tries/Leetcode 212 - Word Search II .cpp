// Problem Link: https://leetcode.com/problems/word-search-ii/
// Time Complexity: O(M × N × 4 × L) - Worst Case Scenario

class Solution {
    struct TrieNode{
        TrieNode* children[26];
        string word;
        TrieNode(){
            for(int i = 0; i < 26; i++) children[i] = nullptr;
            word = "";
        }
    };

    void insert(TrieNode* root, const string& word){
        TrieNode* node = root;
        for(char c : word){
            int idx = c - 'a';
            if(node -> children[idx] == nullptr) node -> children[idx] = new TrieNode();
            node = node -> children[idx];
        }
        node -> word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result){
        char c = board[i][j];
        if(c == '#' || node ->children[c - 'a'] == nullptr) return;
        node = node -> children[c - 'a'];
        if(!node -> word.empty()){
            result.push_back(node -> word);
            node -> word.clear();
        }
        board[i][j] = '#';
        if(i > 0) dfs(board, i - 1, j, node, result);
        if(j > 0) dfs(board, i, j - 1, node, result);
        if(i < board.size() - 1) dfs(board, i + 1, j, node, result);
        if(j < board[0].size() - 1) dfs(board, i, j + 1, node, result);

        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string& word : words) insert(root, word);
        vector<string> result;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++) dfs(board, i, j, root, result);
        }
        return result;
    }
};