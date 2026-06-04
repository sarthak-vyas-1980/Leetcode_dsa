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
public:
    Node* connect(Node* root) {
        if(!root) return NULL;

        if(root->left) root->left->next = root->right;
        if(root->right && root->next) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);

        return root;

        // if(!root) return root;
        // queue<Node*> q;
        // q.push(root);

        // while(!q.empty()){
        //     int size = q.size();
        //     Node* nextNode = NULL;

        //     for(int i=0; i<size; i++){
        //         Node* temp = q.front();
        //         q.pop();

        //         temp->next = nextNode;
        //         nextNode = temp;
                
        //         if(temp->right) q.push(temp->right);
        //         if(temp->left) q.push(temp->left);
        //     }
        // }
        // return root;
    }
};