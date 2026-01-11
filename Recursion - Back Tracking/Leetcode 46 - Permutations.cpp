// Problrm Link: https://leetcode.com/problems/permutations/
// Time Complexity: O(2^n)

class Solution {
public:
    void permutations(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans, vector<bool>& used){
        if(nums.size() == curr.size()){
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(used[i]) continue;

            used[i] = true;
            curr.push_back(nums[i]);
            permutations(nums, curr, ans, used);
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> used(nums.size(), false);
        vector<int> curr;
        permutations(nums, curr, ans, used);
        return ans;
    }
};