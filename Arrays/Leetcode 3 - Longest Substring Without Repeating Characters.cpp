// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Time Complexity: O(N)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 0) return 0;
        int left = 0, best = INT_MIN;
        vector<int> freq(256, 0);
        for(int right = 0; right < s.size(); right++){
            freq[s[right]]++;

            while(freq[s[right]] > 1) {
                freq[s[left]]--;
                left++;
            }

            best = max(best, right - left + 1);
        }
        return best;
    }
};