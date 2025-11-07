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
    bool recursion(TreeNode* root,long long min,long long max){
        if(root==NULL)return true;
        if(root->val >min && root->val <max){
            bool a=recursion(root->left,min,root->val);
            bool b=recursion(root->right,root->val,max);
            return (a && b);

        }
        else{
            return false;
        }

    }
public:
    bool isValidBST(TreeNode* root) {
        // return recursion(root,INT_MIN,INT_MAX);
        return recursion(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }
};