// Problem Link: https://leetcode.com/problems/coin-change/
// Time Complexity: O(n * amount)

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int coin : coins){
                if(i - coin >= 0) dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};
