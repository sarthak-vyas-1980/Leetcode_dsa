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
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        int pos=1;
        ListNode*temp=head;
        ListNode*leftext= NULL;
        ListNode*leftP= NULL;
        ListNode*rightP= NULL;
        ListNode*rightext= NULL;

        while(temp!=NULL && pos<=right+1){
            if(pos==left-1) leftext=temp;
            else if(pos==left) leftP=temp;            
            else if(pos==right) rightP=temp;            
            else if(pos==right+1) rightext=temp;
            pos++;
            temp=temp->next;            
        }
        ListNode*prev=NULL;
        ListNode*curr=leftP;
        ListNode*next=NULL;
        while(prev!=rightP){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        leftP->next=rightext;
        if(leftext==NULL) return rightP;
        leftext->next=rightP;

        if(leftP==head) return rightP;
        return head;
    }
};