// Problem Link: https://leetcode.com/problems/number-of-1-bits/
// Time Complexity: O(total bits)

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n){
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
};