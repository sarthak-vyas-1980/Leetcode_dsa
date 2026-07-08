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
    int solve(TreeNode* root, int& ans){
        if(!root) return 0;

        int left = solve(root->left, ans);
        int right = solve(root->right, ans);

        int single_path = root->val + max(left, right);
        int double_path = root->val + left + right;
        ans = max(ans, max(root->val, max(single_path, double_path)));
        return max(single_path, root->val);
    }
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return -1;
        int ans = root->val;

        int fullPath = solve(root, ans);
        return max(ans, fullPath);
    }
};