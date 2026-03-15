// Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum/
// Time Complexity: O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int minIndxs = INT_MAX, sum = 0;

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                minIndxs = min(minIndxs, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return minIndxs == INT_MAX ? 0 : minIndxs;
    }
};