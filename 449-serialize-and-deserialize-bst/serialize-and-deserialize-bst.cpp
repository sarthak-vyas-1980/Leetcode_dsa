/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void preorder(TreeNode* root, string& traversal){
        if(!root){
            traversal += "null ";
            return ;
        }
        traversal += to_string(root->val);
        traversal.push_back(' ');
        preorder(root->left, traversal);
        preorder(root->right, traversal);
    }
    TreeNode* constructTree(string& data, int& i){
        if(i>=data.length()) return NULL;
        int j = i;
        while(i<data.length() && data[i]!=' ') i++;
        string temp = data.substr(j, i-j);
        i++;

        if(temp == "null") return NULL;
        else{
            int val = stoi(temp);
            TreeNode* node = new TreeNode(val);
            node->left = constructTree(data, i);
            node->right = constructTree(data, i);
            return node;
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string traversal = "";
        preorder(root, traversal);
        return traversal;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        return constructTree(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;