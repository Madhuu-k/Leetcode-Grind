// Problem Link: https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
// Time Complexity: O(N.L)

class WordDictionary {
public:
    struct Trie{
        Trie* children[26];
        bool isEnd;
        Trie(){
            isEnd = false;
            for(int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    Trie* root;

    WordDictionary() {
        root = new Trie();
    }

    void addWord(string word) {
        Trie* node = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(node -> children[idx] == nullptr) node -> children[idx] = new Trie();
            node = node -> children[idx];
        }
        node -> isEnd = true;
    }

    bool dfs(Trie* node, string& word, int index){
        if(node == nullptr) return false;
        if(index == word.size()) return node -> isEnd;
        char ch = word[index];
        if(ch == '.'){
            for(int i = 0; i < 26; i++){
                if(node -> children[i] != nullptr){
                    if(dfs(node -> children[i], word, index + 1)) return true;
                }
            }
            return false;
        }
        else {
            int idx = ch - 'a';
            return dfs(node -> children[idx], word, index + 1);
        }
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
