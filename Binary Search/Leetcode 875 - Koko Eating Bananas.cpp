// Problem Link: https://leetcode.com/problems/koko-eating-bananas/
// Time Complexity: O(n⋅log(max(piles)))

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int m = l + (r - l) / 2;
            int hours = 0;
            for(int pile : piles) hours += (pile + m - 1) / m;
            if(hours <= h) r = m; // move left for smaller
            else l = m + 1; // move right - not sufficient time
        }
        return l;
    }
};
