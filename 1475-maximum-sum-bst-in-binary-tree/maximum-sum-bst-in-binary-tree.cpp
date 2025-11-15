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
 class info {
    public:
    int maxi;
    int mini;
    bool isBst;
    int sum;
};
class Solution {
    info solve(TreeNode* root, int& answer){
        if(root==NULL){
            info temp = {INT_MIN, INT_MAX, true, 0};
            return temp;
        }
        info left = solve(root->left, answer);
        info right = solve(root->right, answer);
        info ans;
        ans.sum = left.sum + right.sum + root->val;
        ans.mini = min(root->val, left.mini);
        ans.maxi = max(root->val, right.maxi);
        if(left.isBst && right.isBst && (root->val>left.maxi && root->val<right.mini)){
            ans.isBst = true;
            answer = max(answer, ans.sum);
        } else {
            ans.isBst = false;
        }
        return ans;
    }
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        info temp = solve(root, maxSum);
        return maxSum;
    }
};