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
    void inOrder(TreeNode* root, vector<int>& nums) {
        if (root == NULL)
            return;
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        vector<int> nums;
        inOrder(root, nums);
        int left, right, mid, mn = -1, mx = -1;
        for (int i = 0; i < queries.size(); i++) {
            left = 0, right = nums.size()-1, mn = -1, mx = -1;
            while (left <= right) {
                mid = (left + right) / 2;
                if (nums[mid] <= queries[i]) {
                    mn = nums[mid];
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            left = 0, right = nums.size()-1;
            while (left <= right) {
                mid = (left + right) / 2;
                if (nums[mid] >= queries[i]) {
                    mx = nums[mid];
                    right = mid - 1;

                } else {
                    left = mid + 1;
                }
            }
            ans.push_back({mn, mx});
        }
        return ans;
    }
};