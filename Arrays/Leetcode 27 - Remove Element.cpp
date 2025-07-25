// Problem Link: https://leetcode.com/problems/remove-element/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val) nums[index++] = nums[i];
        }
        return index;
    }
};