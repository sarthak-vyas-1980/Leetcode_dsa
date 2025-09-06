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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = NULL;
        int count=0;

        int cnt=0;
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        if(cnt<2) return head;
        curr=head;

        while(curr!=NULL && 2>count){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
            count++;
        }

        if(forw!=NULL){
            head->next=swapPairs(forw);
        }
        return prev;
    }
};

// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head==NULL) return NULL;

//         ListNode* prev = NULL;
//         ListNode* curr = head;
//         ListNode* forw = NULL;
//         int count=0;

//         int cnt=0;
//         while(curr!=NULL){
//             curr=curr->next;
//             cnt++;
//         }
//         if(cnt<k) return head;
//         curr=head;

//         while(curr!=NULL && k>count){
//             forw=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forw;
//             count++;
//         }

//         if(forw!=NULL){
//             head->next=reverseKGroup(forw,k);
//         }
//         return prev;
//     }
// };