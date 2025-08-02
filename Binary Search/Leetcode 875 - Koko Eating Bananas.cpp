// Problem Link: https://leetcode.com/problems/koko-eating-bananas/
// Time Complexity: O(n⋅log(max(piles)))

class Solution {
public:
    bool canEatAll(vector<int>& piles, int h, int k){
        long long hours = 0;
        for(int pile : piles) hours += (pile + k - 1) / k;
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(canEatAll(piles, h, mid)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};