// Problem Link: https://leetcode.com/problems/path-sum/
// Time Complexity: o(n)

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
    bool pathSum(TreeNode* root, int targetSum, int currentSum){
        if(root == nullptr) return false;
        currentSum += root -> val;
        if(!root -> left && !root -> right) return currentSum == targetSum;

        bool left = pathSum(root -> left, targetSum, currentSum);
        bool right = pathSum(root -> right, targetSum, currentSum);
        return left || right;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathSum(root, targetSum, 0);
    }
};