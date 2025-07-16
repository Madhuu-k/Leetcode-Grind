// Problem Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/submissions/1696171501/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target) {
                if(first == -1) first = i;
                last = i;
            }
        }

        return {first, last};
    }
};

