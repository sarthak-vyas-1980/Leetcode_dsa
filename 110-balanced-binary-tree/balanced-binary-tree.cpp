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
    pair<bool,int> solve(TreeNode* root){
        if(root==NULL) return {true,0};
        pair<bool,int>left = solve(root->left);
        pair<bool,int>right = solve(root->right);

        bool opt1 = left.first;
        bool opt2 = right.first;
        bool opt3 = abs(left.second - right.second) <= 1;

        pair<bool,int>ans;
        ans.first = opt1 && opt2 && opt3;
        ans.second = max(left.second, right.second) +1;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        pair<bool, int> ans = solve(root);
        return ans.first;
    }
};