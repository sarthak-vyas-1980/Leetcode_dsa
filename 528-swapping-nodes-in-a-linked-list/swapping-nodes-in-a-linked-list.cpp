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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        ListNode* first, *last = head, *temp = head;
        dummy->next = head;

        while(temp && k--){
            first = temp;
            temp = temp->next;
        }
        while(temp){
            last = last->next;
            temp = temp->next;
        }

        swap(first->val, last->val);
        return dummy->next;
    }
};