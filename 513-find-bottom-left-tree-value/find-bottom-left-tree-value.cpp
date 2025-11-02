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
    void solve(TreeNode* root, int& h, int lvl, int& ans){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            if(lvl>h){
                h = lvl;
                ans = root->val;
            }
        }
        solve(root->left, h, lvl+1, ans);
        solve(root->right, h, lvl+1, ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return -1;
        if(root->left==NULL && root->right==NULL) return root->val;
        int ans = root->val;
        int h = 0;
        solve(root, h, 0, ans);
        return ans;
    }
};