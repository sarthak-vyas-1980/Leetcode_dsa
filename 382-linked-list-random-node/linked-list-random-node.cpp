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
    ListNode* Lhead;
public:
    Solution(ListNode* head) {
        Lhead = head;
    }
    
    int getRandom() {
        int res = Lhead->val;
        int i = 2;
        ListNode* curr = Lhead->next;

        while(curr){
            if(rand() % i == 0) res = curr->val;
            curr = curr->next;
            i++;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */