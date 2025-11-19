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
class compare{
    public: 
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // priority_queue<ListNode*, vector<ListNode*>, greater<ListNode*>> minHeap;

        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]) minHeap.push(lists[i]);
        }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!minHeap.empty()){
            ListNode* top = minHeap.top();
            minHeap.pop();
            if(!head){
                head = top;
                tail = top;
            }
            else {
                tail->next = top;
                tail = tail->next;

            }
            if(top->next) minHeap.push(top->next);
        }
        return head;
    }
};