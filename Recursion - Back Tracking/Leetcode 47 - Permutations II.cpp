// Problem Link: https://leetcode.com/problems/permutations-ii/
// Time Complexity: O(n.n!)

class Solution {
public:
    void Permutations(vector<int>& nums, vector<int>& curr, vector<bool>& used, vector<vector<int>>& ans){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;

            if(i > 0 && nums[i] == nums[i-1] && !used[i - 1]) continue;

            // Pick
            used[i] = true;
            curr.push_back(nums[i]);
            Permutations(nums, curr, used, ans);

            // Not Pick
            curr.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        sort(nums.begin(), nums.end());
        Permutations(nums, curr, used, ans);
        return ans;
    }
};