// Problem Link: https://leetcode.com/problems/running-sum-of-1d-array/
// Time Complexity: O(n)

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            int sum = nums[i] + res[i - 1];
            res.push_back(sum);
        }
        return res;
    }
};