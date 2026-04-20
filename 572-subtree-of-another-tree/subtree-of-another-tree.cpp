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
    bool checkEqual(TreeNode* root, TreeNode* subroot){
        if(root==NULL && subroot==NULL) return true;
        if(root==NULL && subroot!=NULL) return false;
        if(root!=NULL && subroot==NULL) return false;

        if(root->val != subroot->val) return false;
        bool left = checkEqual(root->left, subroot->left);
        bool right = checkEqual(root->right, subroot->right);
        return left && right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL) return false;

        if(subRoot != NULL && root->val == subRoot->val){
            if(checkEqual(root, subRoot)) return true;
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return left || right;
    }
};