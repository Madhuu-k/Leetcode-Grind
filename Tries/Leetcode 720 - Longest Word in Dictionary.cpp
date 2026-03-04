// Problem Link: https://leetcode.com/problems/longest-word-in-dictionary/
// Time Complexity: O(N*L)

class Solution {
public:
    struct Trie{
        string word;
        bool isEnd;
        Trie* children[26];
        Trie(){
            word = "";
            isEnd = false;
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    void insert(Trie* root, string word){
        Trie* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(node -> children[idx] == nullptr) node -> children[idx] = new Trie();
            node = node -> children[idx];
        }
        node -> word = word;
        node -> isEnd = true;
    }

    string longestWord(Trie* root, vector<string>& words){
        string ans = "";
        for(string word : words){
            Trie* node = root;
            bool valid = true;
            for(char ch : word){
                int idx = ch - 'a';
                if(node->children[idx] == nullptr){
                    valid = false;
                    break;
                }
                node = node->children[idx];
                if(node->isEnd == false){
                    valid = false;
                    break;
                }
            }
            if(valid){
                if(word.length() > ans.length() ||
                  (word.length() == ans.length() && word < ans)){
                    ans = word;
                  }
            }
        }

        return ans;
    }

    string longestWord(vector<string>& words) {
        Trie* root = new Trie();
        for(string word : words) insert(root, word);
        return longestWord(root, words);
    }
};