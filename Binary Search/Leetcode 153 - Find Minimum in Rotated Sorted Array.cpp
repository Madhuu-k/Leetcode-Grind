// Problem Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Time Complexity: o(log n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
};