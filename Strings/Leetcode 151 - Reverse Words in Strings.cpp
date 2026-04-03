// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/description/
// Time Complexity: O(n)

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        while(ss >> word) words.push_back(word);
        reverse(words.begin(), words.end());

        string res = "";
        for(string w : words) res += w + " ";
        if(!res.empty()) res.pop_back();

        return res;
    }
};