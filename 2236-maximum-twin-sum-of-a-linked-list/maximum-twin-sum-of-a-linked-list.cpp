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
    int pairSum(ListNode* head) {
        vector<int> ans;
        int size = 0;
        int sum = INT_MIN;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;

        while(curr){
            size++;
            ans.push_back(curr->val);
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        for(int i=size-1; i>=size/2; i--){
            ans[size-i-1] += prev->val;
            sum = max(sum, ans[size-i-1]);
            prev = prev->next;
        }
        return sum;
    }
};