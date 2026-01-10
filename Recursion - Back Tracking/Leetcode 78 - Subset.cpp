// Problem Link: https://leetcode.com/problems/subsets/
// Time Complexity: O(n.2^n)

class Solution {
public:
    void GetSubsets(vector<int>& nums, vector<vector<int>>& ans, int i, vector<int>& curr){
        if(i == nums.size()){
            ans.push_back(curr);
            return;
        }
        // Take
        curr.push_back(nums[i]);
        GetSubsets(nums, ans, i + 1, curr);

        // Dont Take
        curr.pop_back();
        GetSubsets(nums, ans, i + 1, curr);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        GetSubsets(nums, ans, 0, curr);
        return ans;
    }
};

