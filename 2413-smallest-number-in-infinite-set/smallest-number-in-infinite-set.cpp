class SmallestInfiniteSet {
    int curr;
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> s;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(!pq.empty()){
            int num = pq.top();
            pq.pop();
            s.erase(num);
            return num;
        }
        return curr++;
    }
    
    void addBack(int num) {
        if(num < curr && !s.count(num)){
            pq.push(num);
            s.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */