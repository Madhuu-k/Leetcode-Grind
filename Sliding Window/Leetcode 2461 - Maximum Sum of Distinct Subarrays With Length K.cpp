// Problem Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
// Time Complexity: O(n)

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0, sum = 0;
        int left = 0;
        unordered_map<int, int> map;

        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];
            map[nums[right]]++;

            while(map[nums[right]] > 1 || right - left + 1 > k){
                map[nums[left]]--;
                sum -= nums[left];
                left++;
            }

            if(right  - left + 1 == k) maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};