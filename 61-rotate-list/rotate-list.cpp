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
    ListNode* rotateRight(ListNode* head, int k) {
        if( head==NULL )return head;
        if(k==0) return head;
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL){
            cnt++;
            temp = temp->next;
        }
        k = k%cnt;
        if(k==0) return head;

        temp = head;
        ListNode* start = NULL;
        ListNode* end = NULL;
        while( temp!=NULL && cnt!=0){
            if(cnt ==1){
                end = temp;
                break;
            }
            if(cnt == k+1){
                start = temp->next;
                temp->next = NULL;
                temp = start;
                cnt--;
            } else {
                cnt--;
                temp = temp->next;
            }
        }
        if(end!=NULL){
            end->next = head;
            return start;
        }
        return head;
    }
};