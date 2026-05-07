// Problem Link: https://leetcode.com/problems/jump-game-ii/
// Time Complexity: o(n)

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int jumps = 0, farthest = 0, currEnd = 0;
        for(int i = 0; i < nums.size(); i++){
            farthest = max(farthest, i + nums[i]);
            if(i == currEnd){
                jumps++;
                currEnd = farthest;
                if(currEnd >=  nums.size() - 1) break;
            }
        }
        return jumps;
    }
};