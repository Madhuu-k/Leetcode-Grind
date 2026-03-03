// Problem Link: https://leetcode.com/problems/implement-trie-prefix-tree/
// Time Complexity: O(l)

class Trie {
public:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            isEnd = false;
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for(char ch : word){
            int index = ch - 'a';
            if(node -> children[index] == nullptr) node -> children[index] = new TrieNode();
            node = node -> children[index];
        }
        node -> isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(node -> children[index] == nullptr) return false;
            node = node -> children[index];
        }
        return node -> isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(char ch : prefix) {
            int index = ch - 'a';
            if(node -> children[index] == nullptr) return false;
            node = node -> children[index];
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