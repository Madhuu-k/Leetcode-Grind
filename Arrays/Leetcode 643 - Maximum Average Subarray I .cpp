// Problem Link: https://leetcode.com/problems/maximum-average-subarray-i/
// Time Complexity: O(n)

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];

        int left = 0, sum = 0;
        double Maxavg = -1e18;
        for(int right = 0; right < nums.size(); right++){
            sum += nums[right];

            if(right - left + 1 == k){
                double avg = (double)sum / k;
                Maxavg = max(Maxavg, avg);

                sum -= nums[left];
                left++;
            }
        }
        return Maxavg;
    }
};