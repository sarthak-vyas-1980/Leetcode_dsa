/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* temp1 = headA;
        unordered_map<ListNode*, bool>visited;

        while(temp1!=NULL){
            visited[temp1] = true;
            temp1 = temp1->next;
        }
        ListNode* temp2 = headB;
        while(temp2!=NULL){
            if(visited[temp2]){
                return temp2;
            }
            temp2 = temp2->next;
        }
        return NULL;

    }
};