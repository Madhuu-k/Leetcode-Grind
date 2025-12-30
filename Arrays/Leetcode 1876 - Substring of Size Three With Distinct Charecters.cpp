// Problem Link: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
// Time Complexity: O(N)

class Solution {
public:
    int countGoodSubstrings(string s) {
        int left = 0, count = 0;
        unordered_map<char, int> freq;

        for(int right = 0; right < s.length(); right++){
            freq[s[right]]++;

            while(right - left + 1 == 3){
                if(freq.size() == 3) count++;
                freq[s[left]]--;
                if(freq[s[left]] == 0) freq.erase(s[left]);
                left++;
            }
        }
        return count;
    }
};