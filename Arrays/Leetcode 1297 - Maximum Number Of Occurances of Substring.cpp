// Problem Link: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/
// Time Complexity: O(n)

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<char, int> freq;
        unordered_map<string, int> subFreq;

        int left = 0, ans = 0;

        for(int right = 0; right < s.length(); right++){
            freq[s[right]]++;

            if(right - left + 1 > minSize){
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }

            if(right - left + 1 == minSize){
                if(freq.size() <= maxLetters){
                    string sub = s.substr(left, minSize);
                    ans = max(ans, ++subFreq[sub]);
                }
            }
        }
        return ans;
    }
};