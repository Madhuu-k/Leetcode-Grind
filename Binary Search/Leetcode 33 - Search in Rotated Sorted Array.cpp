// Problem Link: https://leetcode.com/problems/search-in-rotated-sorted-array/?envType=problem-list-v2&envId=array
// Time Complexity: O(log n)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] == target) return m;

            // Search Left
            if(nums[l] <= nums[m]){
                if(nums[l] <= target && nums[m] >= target) r = m - 1;
                else l = m + 1;
            }

            // Search Right
            else{
                if(nums[m] <= target && nums[r] >= target) l = m + 1;
                else r = m - 1;
            }
        }
        return -1;
    }
};
