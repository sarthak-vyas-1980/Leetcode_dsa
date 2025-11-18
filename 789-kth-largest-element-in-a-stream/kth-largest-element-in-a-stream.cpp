class KthLargest {
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int i = 0;
        while(i<nums.size() && pq.size()<k){
            pq.push(nums[i++]);
        }
        while(i<nums.size()){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
            i++;
        }
    }
    
    int add(int val) {
        if(k>pq.size()) pq.push(val);
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */