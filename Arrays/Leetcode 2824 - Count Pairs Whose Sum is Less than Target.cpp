// Problem Link: https://leetcode.com/problems/count-pairs-whose-sum-is-less-than-target/
// Time Complexity: O(n logn)

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int count = 0;
        while(left < right){
            if(nums[left] + nums[right] < target){
                count += (right - left);
                left++;
            }
            else right--;
        }
        return count;
    }
};