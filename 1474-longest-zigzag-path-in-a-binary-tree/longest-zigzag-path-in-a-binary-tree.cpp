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
    int ans;

    void solve(TreeNode* root, bool r, int count){
        if(!root) return ;
        ans = max(ans, count);
        if(root->left && r) solve(root->left, 0, count + 1);
        else solve(root->left, 0, 1);

        if(root->right && !r) solve(root->right, 1, count + 1);
        else solve(root->right, 1, 1);
    }
public:
    int longestZigZag(TreeNode* root) {
        ans = 0;
        if(root->left) solve(root->left, 0, 1);
        if(root->right) solve(root->right, 1, 1);
        return ans;
    }
};