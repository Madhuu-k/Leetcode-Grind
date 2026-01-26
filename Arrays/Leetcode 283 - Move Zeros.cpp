// Problem Link: https://leetcode.com/problems/move-zeroes/
// Time Complexity: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0) nums[idx++] = nums[i];
        }
        while(idx < n) nums[idx++] = 0;
    }
};