/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    void deleteNode(ListNode*& head, ListNode*& curr, ListNode*& prev){
        if(prev==NULL || curr==head){
            ListNode* temp=head;
            head=head->next;
            curr=head;
            temp->next=NULL;
            delete temp;
        } else {
            prev->next=curr->next;
            ListNode*temp=curr;
            curr=curr->next;
            temp->next=NULL;
            delete temp;
        }
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            if(curr->val==val){
                deleteNode(head, curr, prev);
            }
            else{
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};