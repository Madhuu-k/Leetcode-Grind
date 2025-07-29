// Problem Link: https://leetcode.com/problems/jump-game-ii/
// Time Complexity: o(n)

class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0, jumps = 0, currEnd = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            farthest = max(farthest, i + nums[i]);
            if(i == currEnd){
                jumps++;
                currEnd = farthest;
            }
        }
        return jumps;
    }
};