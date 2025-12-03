// THIS RAN INTO TLE BECAUSE OF ITS TIME COMPLEXITY - O(n*k)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1) return nums;
        vector<int> result;
        int left = 0;

        for(int right = 0; right < nums.size(); right++){
            int maxElement = INT_MIN;

            if(right - left + 1 == k) {
                for(int i = left; i <= right; i++) maxElement = max(maxElement, nums[i]);
                result.push_back(maxElement);
                left++;
            }
        }
        return result;
    }
};