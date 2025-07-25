// Problem Link: https://leetcode.com/problems/next-permutation/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) i--;
        if(i >= 0){
            int j = n - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + 1 + i, nums.end());
    }
};