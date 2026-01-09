// Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX, left = 0, sum = 0;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                min_len = min(min_len, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
};