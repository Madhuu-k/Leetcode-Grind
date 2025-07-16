// Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, n = nums.size(), minLen = INT_MAX, sum = 0;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(sum >= target){
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left ++;
            }
        }
        return (minLen == INT_MAX) ? 0 : minLen;
    }
};