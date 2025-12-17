// Problem Link: https://leetcode.com/problems/balanced-binary-tree/description
// Time Complexity: o(n)
class Solution {
public:
    int check(TreeNode* root) {
        if(root == nullptr) return 0;

        int leftH = check(root -> left);
        if(leftH == -1) return -1;

        int rightH = check(root -> right);
        if(rightH == -1) return -1;

        if(abs(leftH - rightH) > 1) return -1;

        return 1 + max(leftH, rightH);
    }

    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }

};