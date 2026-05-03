// Problem Link: https://leetcode.com/problems/jump-game-ii/
// Time Complexity: o(n)

class Solution {
public:
    int jump(vector<int>& nums) {
        int totalJumps = 0;
        int farthest = 0;
        int currentPoint = 0;

        for(int i = 0; i < nums.size() - 1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == currentPoint){
                totalJumps++;
                currentPoint = farthest;
            }
        }

        return totalJumps;
    }
};