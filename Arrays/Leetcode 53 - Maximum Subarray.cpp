// Problem Link: https://leetcode.com/problems/maximum-subarray/
// Time Complexity: O(n)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int maxSum = INT_MIN, sum = 0, prevMax = 0;
        for(int x : nums){
            sum += x;
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};