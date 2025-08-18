// Problem Link: https://leetcode.com/problems/stream-of-characters/
// Time Complexity: O(N × L + Q × Lmax)

class StreamChecker {
    struct Trie{
        Trie* children[26];
        bool isEnd;
        Trie(){
            fill(begin(children), end(children), nullptr);
            isEnd = false;
        }
    };

    Trie* root = new Trie();
    string stream = "";

    void insert(string word){
        Trie* node = root;
        for(int i = word.size() - 1; i >= 0; i--){
            int idx = word[i] - 'a';
            if(!node -> children[idx]) node -> children[idx] = new Trie();
            node = node -> children[idx];
        }
        node -> isEnd = true;
    }
public:
    StreamChecker(vector<string>& words) {
        for(string& w : words) insert(w);
    }

    bool query(char letter) {
        stream.push_back(letter);
        Trie* node = root;
        for(int i = stream.size() - 1; i >= 0 && node; i--){
            int idx = stream[i] - 'a';
            node = node -> children[idx];
            if(!node) return false;
            if(node -> isEnd) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */