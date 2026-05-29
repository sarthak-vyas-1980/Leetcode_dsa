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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;
        s.push(0);

        while(head){
            ans.push_back(head->val);
            head = head->next;
        }
        for(int i=ans.size()-1; i>=0; i--){
            int top = ans[i];
            while(s.top() <= ans[i] && s.top() != 0) s.pop();
            ans[i] = s.top();
            s.push(top);
        }
        return ans;
    }
};