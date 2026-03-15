// Problem Link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Time Complexity: O(n)

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(p.size() > s.size()) return result;
        vector<int> freqS(26, 0), freqP(26, 0);
        int left = 0;
        for(char c : p) freqP[c - 'a']++;

        for(int right = 0; right < s.size(); right++){
            freqS[s[right] - 'a']++;
            if(right - left + 1 == p.size()){
                if(freqS == freqP) result.push_back(left);
                freqS[s[left] - 'a']--;
                left++;
            }
        }

        return result;
    }
};