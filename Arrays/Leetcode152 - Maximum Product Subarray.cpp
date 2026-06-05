// Problem Link: https://leetcode.com/problems/maximum-product-subarray/
// Time Complexity: O(n)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxSoFar = nums[0], minSoFar = nums[0];
        int ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
            int x = nums[i];

            int newMax = max({x, x * maxSoFar, x * minSoFar});
            int newMin = min({x, x * maxSoFar, x * minSoFar});

            maxSoFar = newMax;
            minSoFar = newMin;

            ans = max(ans, maxSoFar);
        }
        return ans;
    }
};