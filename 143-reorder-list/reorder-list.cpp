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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        ListNode* tail = NULL;

        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast && fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }

        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(mid){
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }

        tail = prev;
        while(temp){
            next = temp->next;
            temp->next = tail;
            temp = next;
            if(temp == NULL) return;
            next = tail->next;
            tail->next = temp;
            tail = next;
        }
    }
};