// Problem Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
// Time Complexity: O(n)

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i+1)%n]) count++;
        }
        return count <= 1;
    }
};