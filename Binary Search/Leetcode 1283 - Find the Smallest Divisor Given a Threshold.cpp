// Problem Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
// Time Complexity: O(N * log(M))

class Solution {
public:
    int compute(vector<int>& nums, int divisor){
        int sum = 0;
        for(int num : nums) sum += (num + divisor - 1) / divisor;
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int currSum = compute(nums, mid);

            if(currSum <= threshold){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};