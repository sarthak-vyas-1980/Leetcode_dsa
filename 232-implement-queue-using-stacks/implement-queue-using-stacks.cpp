class MyQueue {
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()){
            int val = s1.top();
            s1.pop();
            s2.push(val);
        }
        s2.push(x);
        while(!s2.empty()){
            int val = s2.top();
            s2.pop();
            s1.push(val);
        }
    }
    
    int pop() {
        if(s1.empty()) return -1;
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        if(s1.empty()) return -1;
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */