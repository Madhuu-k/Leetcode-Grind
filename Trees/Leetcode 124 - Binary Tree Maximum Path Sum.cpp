// Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
    int maxSum = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }

    int dfs(TreeNode* root){
        if(root== nullptr) return 0;
        int left = max(0, dfs(root -> left));
        int right = max(0, dfs(root -> right));
        maxSum = max(maxSum, left + right + root -> val);
        return root -> val + max(left, right);
    }
};