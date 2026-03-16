// Problem Link:
// Time Complexity: O(n)

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int maxLen = 0, maxFreq = 0, left = 0;
        for(int right = 0; right < s.length(); right++){
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);
            while((right - left + 1) - maxFreq > k){
                freq[s[left] - 'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};