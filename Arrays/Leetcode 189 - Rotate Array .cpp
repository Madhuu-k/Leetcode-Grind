// Problem Link: https://leetcode.com/problems/rotate-array/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    void reverseArray(vector<int>& nums, int start, int end){
        while(start < end) swap(nums[start++], nums[end--]);
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverseArray(nums, 0, n - 1);
        reverseArray(nums, 0, k - 1);
        reverseArray(nums, k, n - 1);
    }
};