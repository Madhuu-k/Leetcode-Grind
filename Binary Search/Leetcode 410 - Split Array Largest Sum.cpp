// Problem Link: https://leetcode.com/problems/split-array-largest-sum/
// Time Complexity: O(N * log(S))

class Solution {
public:
    bool isPossible(vector<int>& nums, int maxSubSum, int k){
        int subArray = 1;
        int currSum = 0;
        for(int num : nums){
            if(currSum + num > maxSubSum){
                subArray++;
                currSum = num;
            }
            else currSum += num;
            if(subArray > k) return false;
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(nums, mid, k)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};