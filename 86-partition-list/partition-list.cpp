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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(0, NULL);
        ListNode* l2 = new ListNode(0, NULL);
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(head){
            if(head->val < x){
                temp1->next = head;
                temp1 = temp1->next;
            } else {
                temp2->next = head;
                temp2 = temp2->next;
            }
            head = head->next;
        }
        temp2->next = nullptr;
        temp1->next = l2->next;
        head = l1->next;
        delete l1;
        delete l2;
        return head;
    }
};