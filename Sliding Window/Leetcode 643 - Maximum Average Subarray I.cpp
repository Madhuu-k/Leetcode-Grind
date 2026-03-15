// Problem Link: https://leetcode.com/problems/maximum-average-subarray-i/
// Time Complexity: O(n)

double findMaxAverage(vector<int>& nums, int k) {
    double maxAvg = INT_MIN;
    double sum = 0;
    int left = 0;
    for(int right = 0; right < nums.size(); right++){
        sum += nums[right];
        while(right - left + 1 == k){
            double avg = sum / k;
            maxAvg = max(maxAvg, avg);
            sum -= nums[left];
            left++;
        }
    }
    return maxAvg;
}