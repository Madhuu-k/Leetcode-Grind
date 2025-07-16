// Problem Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=problem-list-v2&envId=array
// Time Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while(left < right){
            int sum = arr[left] + arr[right];
            if(sum == target) return {left + 1, right + 1};
            else if(sum < target) left ++;
            else right --;
        }
        return {};
    }
};