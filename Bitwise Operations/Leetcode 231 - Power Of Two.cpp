// Problem Link: https://leetcode.com/problems/power-of-two/
// Time Complexity: O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && (n & (n-1)) == 0);
    }
};