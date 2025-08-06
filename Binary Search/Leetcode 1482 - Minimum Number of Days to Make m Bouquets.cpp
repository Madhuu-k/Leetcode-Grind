// Problem Link: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
// Time Complexity: O(N⋅log(max bloomDay))

class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day){
        int count = 0, bouquets = 0;
        for(int i = 0; i < bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
                if(count == k){
                    bouquets++;
                    count = 0;
                }
            }
            else count = 0;
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long flowers = (long long)m * k;
        if(bloomDay.size() < flowers) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canMake(bloomDay, m, k, mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};