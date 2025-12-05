// Problem Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Time Complexity: O(s + p)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(p.size() > s.size()) return result;
        int left = 0;
        vector<int> freqP(26, 0), freqW(26, 0);

        for(char c : p) freqP[c - 'a']++;

        for(int right = 0; right < s.size(); right++) {
            freqW[s[right] - 'a']++;
            if(right - left + 1 == p.size()) {
                if(freqW == freqP) result.push_back(left);
                freqW[s[left] - 'a']--;
                left++;
            }
        }
        return result;
    }
};