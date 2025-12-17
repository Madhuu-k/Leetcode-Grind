// Problem Link: https://leetcode.com/problems/validate-binary-search-tree/
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
    bool isValid(TreeNode* root, long long minVal, long long maxVal){
        if(root == nullptr) return true;
        if(root -> val <= minVal || root -> val >= maxVal) return false;
        return isValid(root -> left, minVal, root -> val) && isValid(root -> right, root -> val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};