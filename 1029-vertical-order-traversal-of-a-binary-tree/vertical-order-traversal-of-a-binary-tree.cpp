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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL) return ans;

        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            nodes[hd][lvl].insert(frontNode->val);

            if(frontNode->left){
                q.push({frontNode->left,{hd-1,lvl+1}});
            }
            if(frontNode->right){
                q.push({frontNode->right,{hd+1,lvl+1}});
            }
        }
        for (auto const& [hd, level_map] : nodes) {
            vector<int> col_nodes;
                for (auto const& [level, val_multiset] : level_map) {
                // Append all sorted values from the multiset
                    col_nodes.insert(col_nodes.end(), val_multiset.begin(), val_multiset.end());
                }
            ans.push_back(col_nodes);
        }
        return ans;
    }
};

// vector<vector<int>> ans;
//         if(root==NULL) return ans;

//         map<int, vector<int>> nodes;
//         queue<pair<TreeNode*,int>> q;
//         q.push({root,0});
//         while(!q.empty()){
//             pair<TreeNode*,int> temp = q.front();
//             q.pop();

//             TreeNode* frontNode = temp.first;
//             int hd = temp.second;
//             nodes[hd].push_back(frontNode->val);

//             if(frontNode->left){
//                 q.push({frontNode->left,hd-1});
//             }
//             if(frontNode->right){
//                 q.push({frontNode->right,hd+1});
//             }
//         }
//         for(auto i: nodes){
//                 ans.push_back(i.second);
//         }
//         return ans;
//     }
// };