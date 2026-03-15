// Problem Link: https://leetcode.com/problems/permutation-in-string/
// Time Complexity: O(n)

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> freqS1(26, 0), freqS2(26, 0);
        for(char c : s1) freqS1[c - 'a']++;
        int left = 0;
        for(int right = 0; right < s2.size(); right++){
            freqS2[s2[right] - 'a']++;
            if(right - left + 1 == s1.size()){
                if(freqS1 == freqS2) return true;
                freqS2[s2[left] - 'a']--;
                left++;
            }
        }
        return false;
    }
};