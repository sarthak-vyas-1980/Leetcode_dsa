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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* prev = dummyNode;
        ListNode* curr = head;

        while(curr){
            while(curr->next != NULL && curr->val == curr->next->val){
                curr = curr->next;
            }
            if(prev->next != curr){
                prev->next = curr->next;
                curr = curr->next;
            } 
            else{
                curr = curr->next;
                prev = prev->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};