// Problem Link: https://leetcode.com/problems/delete-and-earn/
// Time Complexity: O(n + maxVal)

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> points(maxVal + 1, 0);

        int prev2 = 0;
        int prev1 = 0;

        for(int x : nums) points[x] += x;

        for(int i = 0; i <= maxVal; i++){
            int curr = max(prev1, points[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};