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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);

        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second + 1;

        pair<int,int>ans;
        ans.first = max(opt1, max(opt2, opt3));
        ans.second = max(left.second, right.second) +1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if( root==NULL ) return 0;
        pair<int,int> ans = solve(root);
        return ans.first-1;
    }
};