// Problem Link: https://leetcode.com/problems/valid-anagram/
// Time Complexity: O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[256] = {0};
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); i++) freq[s[i] - 'a']++;
        for(int i = 0; i < t.length(); i++) freq[t[i] - 'a']--;
        for(int i = 0; i < 256; i++){
            if(freq[i] != 0) return false;
        }
        return true;
    }
};