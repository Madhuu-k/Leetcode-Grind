// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Time Complexity: O(n)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, left = 0;
        unordered_map<char, int> frq;
        for(int right = 0; right < s.length(); right++){
            frq[s[right]]++;

            while (frq[s[right]] > 1){
                frq[s[left]]--;
                left++;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};