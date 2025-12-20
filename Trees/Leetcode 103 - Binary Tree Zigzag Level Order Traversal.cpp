// Problem Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (root == nullptr) return ans;

    queue<TreeNode*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        int n = q.size();
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (leftToRight)
                dq.push_back(node->val);
            else
                dq.push_front(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.push_back(vector<int>(dq.begin(), dq.end()));
        leftToRight = !leftToRight;
    }
    return ans;
}
