// Problem Link: https://leetcode.com/problems/max-number-of-k-sum-pairs/
// Time Complexity: O(nlogn)

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int pairCount = 0;
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        while(left < right) {
            int sum = nums[left] + nums[right];
            if(sum == k) {
                pairCount++;
                left++; right--;}
            else if(sum < k) left++;
            else right--;
        }
        return pairCount;
    }
};