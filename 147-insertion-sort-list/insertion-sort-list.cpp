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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* start = new ListNode(-1);
        start->next = head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            ListNode* iterator = start->next;
            ListNode* prevIterator = start;

            while(iterator != curr){
                if(iterator->val > curr->val){
                    prev->next = next;

                    prevIterator->next = curr;
                    curr->next = iterator;
                    break;
                }
                prevIterator = iterator;
                iterator = iterator->next;
            }
            curr = next;
            if(prev->next != curr) prev = prev->next;
        }
        return start->next;
    }
};