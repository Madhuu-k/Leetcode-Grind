// Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Time Complexity: O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrices = prices[0], maxPrices = 0;
        for(int x : prices){
            if(x < minPrices) minPrices = x;
            if(x - minPrices > maxPrices) maxPrices = x - minPrices;
        }
        return maxPrices;
    }
};