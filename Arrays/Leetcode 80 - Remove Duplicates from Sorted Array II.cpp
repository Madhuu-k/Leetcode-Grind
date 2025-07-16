// Problem Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 0; j < nums.size(); j++){
            if(i < 2 || nums[j] != nums[i - 2]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};