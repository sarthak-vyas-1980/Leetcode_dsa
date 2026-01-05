/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    void traverse(Node* &node, Node* &ans, unordered_map<Node*, bool>& visited, unordered_map<int, Node*>& mapping){
        visited[node] = true;
        for(auto i: node->neighbors){
            if(!visited[i]){
                Node* newNode = new Node(i->val);
                mapping[i->val] = newNode;
                ans->neighbors.push_back(newNode);
                traverse(i, newNode, visited, mapping);
            } else {
                ans->neighbors.push_back(mapping[i->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        unordered_map<Node*, bool> visited;
        unordered_map<int, Node*> mapping;
        Node* ans = new Node(node->val);

        mapping[node->val] = ans;
        traverse(node, ans, visited, mapping);
        return ans;
    }
};