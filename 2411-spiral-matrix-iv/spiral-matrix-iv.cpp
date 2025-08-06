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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n));
        int count=0,total=m*n;
        int startRow=0;
        int endRow=m-1;
        int startCol=0;
        int endCol=n-1;
        ListNode* curr= head;

        while(count<total){
            for(int i=startCol;count<total && i<=endCol; count++,i++){
                if(curr==NULL){//violating DRY:use a function
                    ans[startRow][i]=-1;
                } else{
                    ans[startRow][i]=curr->val;
                    curr=curr->next;
                }
            }
            startRow++;
            for(int i=startRow;count<total && i<=endRow; count++,i++){
                if(curr==NULL){//violating DRY:use a function
                    ans[i][endCol]=-1;
                } else{
                    ans[i][endCol]=curr->val;
                    curr=curr->next;
                }
            }
            endCol--;
            for(int i=endCol;count<total && i>=startCol; count++,i--){
                if(curr==NULL){//violating DRY:use a function
                    ans[endRow][i]=-1;
                } else{
                    ans[endRow][i]=curr->val;
                    curr=curr->next;
                }
            }
            endRow--;
            for(int i=endRow;count<total && i>=startRow; count++,i--){
                if(curr==NULL){//violating DRY:use a function
                    ans[i][startCol]=-1;
                } else{
                    ans[i][startCol]=curr->val;
                    curr=curr->next;
                }
            }
            startCol++;
        }
        return ans;
    }
};