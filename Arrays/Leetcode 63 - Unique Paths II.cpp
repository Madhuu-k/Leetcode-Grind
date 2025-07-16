// Problem Link: https://leetcode.com/problems/unique-paths-ii/?envType=problem-list-v2&envId=array
// Time Complexity: O(m x n)

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n , 0));
        if(obstacleGrid[0][0] == 1) return 0;

        for(int i = 0; i < m; i++){
            for(int j  = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int leftWay = (i > 0)? dp[i - 1][j] : 0;
                    int downWay = (j > 0)? dp[i][j - 1] : 0;
                    dp[i][j] = leftWay + downWay;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};