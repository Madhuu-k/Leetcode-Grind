// Problem Link: https://leetcode.com/problems/word-search-ii/
// Time Complexity: O(M × N × 4 × L) - Worst Case Scenario
class Solution {
public:
    struct Trie{
        string word;
        Trie* children[26];
        Trie(){
            word = "";
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    vector<string> result;

    void insert(Trie* root, string word){
        Trie* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(node -> children[idx] == nullptr) node -> children[idx] = new Trie();
            node = node -> children[idx];
        }
        node -> word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, Trie* node){
        char ch = board[i][j];
        if(ch == '#' ||  node -> children[ch - 'a'] == nullptr) return;
        node = node -> children[ch - 'a'];

        if(node -> word != ""){
            result.push_back(node -> word);
            node -> word = "";
        }

        board[i][j] = '#';

        int rows = board.size();
        int cols = board[0].size();

        if(i > 0) dfs(board, i - 1, j, node);
        if(j > 0) dfs(board, i, j - 1, node);
        if(i < rows - 1) dfs(board, i + 1, j, node);
        if(j < cols - 1) dfs(board, i, j + 1, node);

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();

        for(string word : words)
            insert(root, word);

        int rows = board.size();
        int cols = board[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                dfs(board, i, j, root);
            }
        }

        return result;
    }
};
