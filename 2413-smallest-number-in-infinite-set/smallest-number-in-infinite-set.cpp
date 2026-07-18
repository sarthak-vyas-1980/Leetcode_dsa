class SmallestInfiniteSet {
    vector<bool> arr;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SmallestInfiniteSet() {
        arr = vector<bool>(1001, 1);
        for(int i=1; i<=1000; i++){
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int num = pq.top();
        pq.pop();
        arr[num] = 0;
        return num;
    }
    
    void addBack(int num) {
        if(arr[num]) return;
        pq.push(num);
        arr[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */