// Problem Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
// Time Complexity: O(N * log(S))


class Solution {
public:
    bool isPossible(vector<int>& weights, int D, int capacity){
        int days = 1;
        int total = 0;
        for(int w : weights){
            if(total + w > capacity){
                days++;
                total = w;
            }
            else total += w;
            if(days > D) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(weights, days, mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};