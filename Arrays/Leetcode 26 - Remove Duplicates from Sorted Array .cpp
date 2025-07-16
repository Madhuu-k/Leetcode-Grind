// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        for(int right = 1; right < nums.size(); right++){
            if(nums[left] != nums[right]){
                left++;
                nums[left] = nums[right];
            }
        }
        return left + 1;
    }
};