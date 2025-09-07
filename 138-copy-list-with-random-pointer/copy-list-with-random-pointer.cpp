/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    void insertAtTail(Node*& head, Node*& tail, int d){
        Node* temp = new Node(d);
        if( head==NULL ){
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
    }
public:
    Node* copyRandomList(Node* head) {

        Node* ansHead = NULL;
        Node* ansTail = NULL;
        Node* temp = head;
        while(temp!=NULL){
            insertAtTail( ansHead, ansTail, temp->val );
            temp = temp->next;
        }

        Node* ogNode = head;
        Node* ansNode = ansHead;
        while(ogNode!=NULL && ansNode!=NULL){
            Node* next = ogNode->next;
            ogNode->next = ansNode;
            ogNode = next;

            next = ansNode->next;
            ansNode->next = ogNode;
            ansNode = next;
        }

        temp = head;
        while(temp!=NULL){
            if(temp->next!=NULL){
                temp->next->random = temp->random ? temp->random->next: temp->random;
            }
            //updation
            if(temp->next!=NULL) temp = temp->next->next;
            else temp = temp->next;
        }

        ogNode = head;
        ansNode = ansHead;
        while(ogNode!=NULL && ansNode!=NULL){
            ogNode->next = ansNode->next;
            ogNode = ogNode->next;
            if(ogNode!=NULL){
                ansNode->next = ogNode->next;
            }
            ansNode = ansNode->next;
        }
        return ansHead;
    }
};