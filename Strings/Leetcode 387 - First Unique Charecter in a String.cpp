// Problem Link: https://leetcode.com/problems/first-unique-character-in-a-string/
// Time Complexity: O(n)

class Solution {
public:
    int firstUniqChar(string s) {
        int freq[256] = {0};
        for(char c : s) freq[c]++;
        for(int i = 0; i < s.length(); i++){
            if(freq[s[i]] == 1) return i;
        }
        return -1;
    }
};