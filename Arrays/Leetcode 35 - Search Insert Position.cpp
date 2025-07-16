// Problem Link: https://leetcode.com/problems/search-insert-position/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i= 0; i < nums.size(); i++){
            if(nums[i] >= target) return i;
        }
        return nums.size();
    }
};