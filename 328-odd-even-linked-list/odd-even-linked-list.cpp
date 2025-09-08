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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* oddNode = NULL;
        ListNode* evenNode = NULL;
        ListNode* evenHead = NULL;
        int count = 1;
        ListNode* temp = head;
        while(temp){
            if(count%2 == 0 ){
                if(count==2){
                    evenHead = temp;
                    evenNode = temp;
                } else{
                    evenNode->next = temp;
                    evenNode = temp;
                }
            }
            else {
                if(count==1){
                    oddNode = temp;
                } else {
                    oddNode->next = temp;
                    oddNode = temp;
                } 
            }
            count++;
            temp=temp->next;
        }
        oddNode->next = evenHead;
        if(evenNode==NULL) return head;
        evenNode->next = NULL;
        return head;
    }
};