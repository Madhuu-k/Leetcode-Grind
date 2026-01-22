// Problem Link: https://leetcode.com/problems/house-robber-ii/
// Time Complexity: O(n)

class Solution {
public:
    int linearRob(vector<int>& nums, int l, int r){
        int prev1 = 0, prev2 = 0;
        for(int i = l; i <= r; i++){
            int curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int first = linearRob(nums, 1, n - 1);
        int second = linearRob(nums, 0,  n - 2);
        return max(first, second);
    }
};