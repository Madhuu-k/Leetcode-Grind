// Problem Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
// Time Complexity: O(n)

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
    int goodNode = 0;
    void checkGood(TreeNode* root, int rootVal){
        if(root == nullptr) return;
        if(root -> val >= rootVal) goodNode++;
        rootVal = max(rootVal, root -> val);
        checkGood(root -> left, rootVal);
        checkGood(root -> right, rootVal);
    }
    int goodNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        checkGood(root, root -> val);
        return goodNode;
    }
};