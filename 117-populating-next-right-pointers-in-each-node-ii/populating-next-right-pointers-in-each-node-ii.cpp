/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    void levelOrderTrav(Node* root, vector<vector<Node*>> &map){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<Node*> path;
            for(int i=0; i<size; i++){
                Node* temp = q.front();
                q.pop();
                path.push_back(temp);
                // temp->next = NULL;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            map.push_back(path);
        }
    }
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        vector<vector<Node*>> map;
        levelOrderTrav(root, map);
        for(int i=1; i<map.size(); i++){
            for(int j=1; j<map[i].size(); j++){
                map[i][j-1]->next = map[i][j];                  
            }
        }
        return root; 
    }
};