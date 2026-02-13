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
    int solve(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return 0;
        int left=INT_MAX, right=INT_MAX;
        if(root->left) left = solve(root->left);
        if(root->right) right = solve(root->right);
        return 1 + min(left, right);

    }
public:
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        return solve(root)+1;
    }
};