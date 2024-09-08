/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> curr;
        while (!q.empty()) {
            TreeNode* child = q.front();
            q.pop();
            if (child) {
                curr.push_back(child->val);
                if (child->left)
                    q.push(child->left);
                if (child->right)
                    q.push(child->right);
            } else {
                ans.push_back(curr);
                curr.clear();
                if (q.size()) {
                    q.push(NULL);
                }
            }
        }
        return ans;
    }
};