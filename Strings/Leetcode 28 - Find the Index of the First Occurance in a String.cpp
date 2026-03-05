// Problem Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
// Time Complexity: O(n.m)

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;
        if(needle.empty()) return 0;
        int pos = 0;
        int n = haystack.size();
        int m = needle.size();
        for(int i = 0; i <= n - m; i++){
            bool valid = true;
            for(int j = 0; j < m; j++){
                if(haystack[i + j] != needle[j]){
                    valid = false;
                    break;
                }
            }
            if(valid){
                return i;
            }
        }
        return -1;
    }
};