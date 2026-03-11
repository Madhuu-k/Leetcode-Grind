// Problem Link: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
// Time Complexity: O(n)

class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char, int> map;
        int left = 0, count = 0;
        for(int right = 0; right < s.length(); right++){
            map[s[right]]++;
            while(right - left + 1 == 3){
                if(map.size() == 3) count++;
                map[s[left]]--;
                if(map[s[left]] == 0) map.erase(s[left]);
                left++;
            }
        }
        return count;
    }
};