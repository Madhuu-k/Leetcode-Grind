// Problem Link: https://leetcode.com/problems/count-complete-tree-nodes/description/
// Time Complexity: o(n)

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};