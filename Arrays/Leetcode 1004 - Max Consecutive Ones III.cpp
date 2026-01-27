// Problem Link: https://leetcode.com/problems/max-consecutive-ones-iii/
// Time Complexity: O(n)

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, zeros = 0, left = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0) zeros++;
            while(zeros > k){
                if(nums[left] == 0) zeros--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};