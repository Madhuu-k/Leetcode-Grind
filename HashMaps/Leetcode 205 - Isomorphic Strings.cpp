// Problem Link: https://leetcode.com/problems/isomorphic-strings/
// Time Complexity: O(n)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(int i = 0; i < s.size(); i++){
            char a = s[i];
            char b = t[i];
            if(mp1.count(a) && mp1[a] != b) return false;
            if(mp2.count(b) && mp2[b] != a) return false;

            mp1[a] = b;
            mp2[b] = a;
        }
        return true;
    }
};