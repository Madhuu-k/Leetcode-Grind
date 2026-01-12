// Problem Link: https://leetcode.com/problems/combination-sum-ii/
// Time Complexity: O(n.logn)

class Solution {
public:
    void combinations(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, int idx, int target){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i - 1]) continue;
            if(nums[i] > target) break;
            // Take
            curr.push_back(nums[i]);
            combinations(nums, curr, ans, i + 1, target - nums[i]);
            // Dont take
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        combinations(candidates, curr, ans, 0, target);
        return ans;
    }
};