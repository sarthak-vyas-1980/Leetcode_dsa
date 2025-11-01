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
    void height(TreeNode* root,int h, bool& z, int x, int y, int& a, int& b){
        if(root==NULL) return;

        if(root->right!=NULL && root->left!=NULL && ((root->left->val==x && root->right->val==y) || (root->left->val==y && root->right->val==x))) z=false;
        if(root->val==x) a=h;
        if(root->val==y) b=h;
        height(root->left, h+1, z, x, y, a, b);
        height(root->right, h+1, z, x, y, a, b);        
        return ;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int a=0, b=0;
        bool z = true;
        height(root, 0, z, x, y, a, b);
        return a==b && z;
    }
};