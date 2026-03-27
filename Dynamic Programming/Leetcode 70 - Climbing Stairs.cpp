// Problem Link: https://leetcode.com/problems/climbing-stairs/
// Time Complexity: O(n)

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        vector<int> d(n + 1);
        d[1] = 1; d[2] = 2;
        for(int i = 3; i <= n; i++) d[i] = d[i - 1] + d[i - 2];
        return d[n];
    }
};