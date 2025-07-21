// Problem Link: https://leetcode.com/problems/path-sum-ii/
// Time Complexity: o(n) * o(k + h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void getPaths(TreeNode* root, int targetSum, int currentSum,
    vector<vector<int>>& result, vector<int>& path){
        if(!root) return;
        currentSum += root -> val;
        path.push_back(root -> val);

        if(!root -> left && !root -> right && currentSum == targetSum)
            result.push_back(path);

        getPaths(root -> left, targetSum, currentSum, result, path);
        getPaths(root -> right, targetSum, currentSum, result, path);
        path.pop_back();

    }


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        getPaths(root, targetSum, 0, result, path);
        return result;
    }
};