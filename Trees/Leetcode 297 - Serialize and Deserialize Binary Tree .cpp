// Problem Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
// Time Complexity: o(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#";
        return to_string(root -> val) + "," +
               serialize(root -> left) + ","+
               serialize(root -> right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string token;
        stringstream ss(data);
        while(getline(ss, token, ',')) q.push(token);
        return buildTree(q);
    }

    TreeNode* buildTree(queue<string>& q){
        if(q.empty()) return nullptr;
        string curr = q.front(); q.pop();
        if(curr == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(curr));
        node -> left = buildTree(q);
        node -> right = buildTree(q);
        return node;
    }
};


