// Problem Link: https://leetcode.com/problems/find-the-difference/
// Time Complexity: O(n)

class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for(char a : s) result ^= a;
        for(char b : t) result ^= b;
        return result;
    }
};