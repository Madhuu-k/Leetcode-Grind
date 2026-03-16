// Problem Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Time Complexity: O(n)

int lengthOfLongestSubstring(string s) {
    unordered_map<int, int> map;
    int left = 0, maxLen = 0;
    for(int right = 0; right < s.length(); right++){
        map[s[right]]++;
        while(map[s[right]] > 1) {
            map[s[left]]--;
            if(map[s[left]] == 0) map.erase(s[left]);
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}