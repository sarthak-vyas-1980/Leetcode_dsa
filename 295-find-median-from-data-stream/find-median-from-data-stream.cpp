class MedianFinder {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    double median;

    void solve(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<int>>& minHeap, double& median, int num){
        if(maxHeap.size() > minHeap.size()){
            if(num > median){
                minHeap.push(num);
                median = (maxHeap.top()+minHeap.top())/2.0;
            } else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
        }
        else if(maxHeap.size() < minHeap.size()){
            if(num > median){
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
                median = (minHeap.top()+maxHeap.top())/2.0;
            } else {
                maxHeap.push(num);
                median = (minHeap.top()+maxHeap.top())/2.0;
            }
        }
        else{
            if(num > median){
                minHeap.push(num);
                median = minHeap.top();
            } else {
                maxHeap.push(num);
                median = maxHeap.top();
            }
        }
    }
public:
    MedianFinder() {
        median = 0.0;
    }
    
    void addNum(int num) {
        solve(maxHeap, minHeap, median, num);
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */