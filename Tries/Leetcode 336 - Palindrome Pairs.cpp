// Problem Link: https://leetcode.com/problems/palindrome-pairs/
// Time Complexity: O(N * K^2)

class Solution {
    struct TrieNode{
        TrieNode* children[26];
        int wordIndex;
        vector<int> palindromeSuffix;

        TrieNode(){
            wordIndex = -1;
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    bool isPalindrome(const string& s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

    void insert(TrieNode* root, const string& word, int index){
        TrieNode* node = root;
        for(int i = word.size() - 1; i >= 0; i--){
            if(isPalindrome(word, 0, i)) node -> palindromeSuffix.push_back(index);
            int c = word[i] - 'a';
            if(!node -> children[c]) node -> children[c] = new TrieNode();
            node = node -> children[c];
        }
        node -> wordIndex = index;
        node -> palindromeSuffix.push_back(index);
    }

    void search(TrieNode* root, const string& word, int index, vector<vector<int>>& result){
        TrieNode* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node -> wordIndex >= 0 && node -> wordIndex != index && isPalindrome(word, i, word.size() - 1)){
                result.push_back({index, node -> wordIndex});
            }
            int c = word[i] - 'a';
            if(!node -> children[c]) return;
            node = node -> children[c];
        }
        for(int otherIndex : node -> palindromeSuffix){
            if(otherIndex != index) result.push_back({index, otherIndex});
        }
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(int i = 0; i < words.size(); i++) insert(root, words[i], i);
        vector<vector<int>> result;
        for(int i = 0; i < words.size(); i++) search(root, words[i], i, result);
        return result;
    }
};

