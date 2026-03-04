// Problem Link: https://leetcode.com/problems/replace-words/
// Time Complexity: O(D.L + N.M)

class Solution {
public:
    struct Trie{
        Trie* children[26];
        string word;
        Trie(){
            word = "";
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
    }

    string searchRoot(Trie* root, string token){
        Trie* node = root;
        for(char ch : token){
            int idx = ch - 'a';
            if(node -> children[idx] == nullptr) return token;
            node = node -> children[idx];
            if(node -> word != "") return node -> word;
        }
        return token;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for(string word : dictionary) insert(root, word);
        stringstream ss(sentence);
        string token, result;
        while(ss >> token){
            string replacement = searchRoot(root, token);
            if(!result.empty()) result += " ";
            result += replacement;
        }
        return result;
    }
};