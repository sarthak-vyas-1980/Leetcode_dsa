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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return NULL;
        ListNode* temp = head;
        int count = 0;
        while(temp){
            count++;
            temp = temp->next;
        }
        int num = count-n;
        if(num==0) return head->next;

        temp = head;
        while(num!=1){
            num--;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     if(!head->next) return NULL;
    //     ListNode* prev = NULL;
    //     ListNode* temp = head;
    //     int i=0;
    //     while(temp!=NULL){
    //         if(i==n){
    //             prev = head;
    //         }
    //         i++;
    //         temp = temp->next;
    //         if(prev && i!=n+1) prev = prev->next;
    //     }
    //     prev->next = prev->next->next;
    //     return head;
    // }
};