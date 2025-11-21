class Node{
    public:
    int data;
    int i;
    int j;
    Node(int d, int i, int j){
        data = d;
        this->i = i;
        this->j = j;
    }
};
class compare {
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);
            minHeap.push(new Node(nums[i][0], i, 0));
        }
        int start = mini, end = maxi;
        while(!minHeap.empty()){
            Node* temp = minHeap.top();
            minHeap.pop();
            mini = temp->data;

            if(maxi-mini < end-start){
                start = mini;
                end = maxi;
            }

            if(temp->j +1 < nums[temp->i].size()){
                maxi = max(maxi, nums[temp->i][temp->j+1]);
                minHeap.push(new Node(nums[temp->i][temp->j+1], temp->i, temp->j+1));
            }
            else break;
        }
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};