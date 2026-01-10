// Problem Link: https://leetcode.com/problems/subsets-ii/
// Time Complexity: O(n.2^n)

class Solution {
public:
    void subsets(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& ans){
        ans.push_back(curr);
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;

            curr.push_back(nums[i]);
            subsets(nums, i + 1, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        subsets(nums, 0, curr, ans);
        return ans;
    }
};