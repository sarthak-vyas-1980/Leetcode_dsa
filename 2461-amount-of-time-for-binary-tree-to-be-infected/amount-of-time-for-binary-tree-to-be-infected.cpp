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
    TreeNode* solve1(TreeNode* root, int start, map<TreeNode*,TreeNode*>& NodeToParent){
        TreeNode* res = NULL;
        if(root==NULL)return res;
        queue<TreeNode*> q;
        q.push(root);
      
        while(!q.empty()){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->val==start) res = temp;
                if(temp->left){
                    NodeToParent[temp->left] = temp;
                    q.push(temp->left);
                }
                if(temp->right){
                    NodeToParent[temp->right] = temp;
                    q.push(temp->right);
                }
        }
        return res;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* target = solve1(root, start, nodeToParent);
        map<TreeNode*, bool> visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int count = 0;
      
        while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int i=0; i<size; i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left && !visited[temp->left]){
                    visited[temp->left] = true;
                    q.push(temp->left);
                    flag = true;
                }
                if(temp->right && !visited[temp->right]){
                    visited[temp->right] = true;
                    q.push(temp->right);
                    flag = true;
                } 
                if(nodeToParent[temp] && !visited[nodeToParent[temp]]){
                    visited[nodeToParent[temp]] = true;
                    q.push(nodeToParent[temp]);
                    flag = true;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};