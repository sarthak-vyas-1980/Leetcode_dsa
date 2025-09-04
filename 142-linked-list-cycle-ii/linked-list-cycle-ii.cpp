/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return NULL;

        ListNode*slow=head;
        ListNode*fast=head;
        while(slow!=NULL&&fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
            }    
            slow=slow->next;
            if (slow==fast){
                return slow;
            }

        }
        return NULL;
    }
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = hasCycle(head);
        if(temp!=NULL){
            while(head!=temp){
                head=head->next;
                temp=temp->next;
            }
            return temp;
        }
        return NULL;
    }
};