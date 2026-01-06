// Problem Link: https://leetcode.com/problems/remove-duplicate-letters/
// Time Complexity: O(n)

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> seen(256, false);
        string result = "";

        vector<int> lastIndex(256, -1);
        int n = s.length();

        for(int i = 0; i < n; i++) lastIndex[s[i]] = i;

        for(int i = 0; i < n; i++){
            char c = s[i];
            if(seen[c]) continue;

            while(!result.empty() && result.back() > c && lastIndex[result.back()] > i){
                seen[result.back()] = false;
                result.pop_back();
            }

            result.push_back(c);
            seen[c] = true;
        }
        return result;
    }
};