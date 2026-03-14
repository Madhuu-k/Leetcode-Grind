// Problem Link: https://leetcode.com/problems/squares-of-a-sorted-array/
// Time Complexity: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, n = nums.size();
        vector<int> res(n);
        int pos = n - 1;
        while(left <= right){
            int leftSqt = nums[left] * nums[left];
            int rightSqt = nums[right] * nums[right];
            if(leftSqt > rightSqt) {
                res[pos] = leftSqt;
                left++;
            }
            else{
                res[pos] = rightSqt;
                right--;
            }
            pos--;
        }
        return res;
    }
};