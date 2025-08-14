// Problem Link: https://leetcode.com/problems/implement-trie-prefix-tree/
// Time Complexity: O(l)

class Trie {
public:
    Trie* children[26];
    bool isEndOfWord;

    Trie() {
        isEndOfWord = false;
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }

    void insert(string word) {
        Trie* node = this;
        for(char ch : word){
            int idx = ch - 'a';
            if(node -> children[idx] == nullptr) node -> children[idx] = new Trie();
            node = node -> children[idx];
        }
        node -> isEndOfWord = true;
    }

    bool search(string word) {
        Trie* node = this;
        for(char ch : word){
            int idx = ch - 'a';
            if(node -> children[idx] == nullptr) return false;
            node = node -> children[idx];
        }
        return node -> isEndOfWord;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for(char ch : prefix){
            int idx = ch - 'a';
            if(node -> children[idx] == nullptr) return false;
            node = node -> children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */