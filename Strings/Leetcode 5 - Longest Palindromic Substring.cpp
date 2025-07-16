// Problem Link: https://leetcode.com/problems/longest-palindromic-substring/
// Time complexity: O(n ^ 2)

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int start = 0, maxLen = 1;
        for(int i = 0; i < s.length(); i++){

            //FOR ODD LENGTH
            int l = i, r = i;
            while(l >= 0 && r <= s.length() && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l + 1;
                }
                l--; r++;
            }

            //FOR EVEN LENGTH
            l = i, r = i + 1;
            while(l >= 0 && r <= s.length() && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l + 1;
                }
                l--; r++;
            }
        }
        return s.substr(start, maxLen);
    }
};