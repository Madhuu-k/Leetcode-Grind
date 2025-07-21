// Problem Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
// Time Complexity: o(n)

class Solution {
public:
    int dfs(TreeNode* root, int& maxSum){
        if(root == nullptr) return 0;
        int left = max(0, dfs(root -> left, maxSum));
        int right = max(0, dfs(root -> right, maxSum));
        maxSum = max(maxSum, left + right + root -> val);
        return root -> val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }
};
