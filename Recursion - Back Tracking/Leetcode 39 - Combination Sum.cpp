// Problem Link: https://leetcode.com/problems/combination-sum/
// Time Complexity: O(2^n)

class Solution {
public:
    void combinations(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int i, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(i == nums.size() || target < 0) return;

        curr.push_back(nums[i]);
        combinations(nums, curr, ans, i, target - nums[i]);

        curr.pop_back();
        combinations(nums, curr, ans, i + 1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        combinations(candidates, curr, ans, 0, target);
        return ans;
    }
};