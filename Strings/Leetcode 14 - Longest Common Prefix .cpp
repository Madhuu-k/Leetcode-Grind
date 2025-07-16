// Problem Link: https://leetcode.com/problems/longest-common-prefix/?envType=problem-list-v2&envId=string
// Time Complexity: o(N log N * M)

class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        if(str.empty()) return "";
        sort(str.begin(), str.end());
        string a = str[0], b = str.back();
        int i = 0;
        while(i < a.size() && a[i] == b[i]) i++;
        return a.substr(0, i);
    }
};