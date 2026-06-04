// Problem Link: https://leetcode.com/problems/find-pivot-index/
// Time Complexity: O(n)

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0, rightSum = 0, totalSum = 0;
        for(int x : nums) totalSum += x;

        for(int i = 0; i < nums.size(); i++){
            rightSum = totalSum - leftSum - nums[i];
            if(leftSum == rightSum) return i;
            leftSum += nums[i];
        }

        return -1;
    }
};