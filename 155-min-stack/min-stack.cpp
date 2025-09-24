class MinStack {
    long long mini;
    stack<long long> s;
public:
    MinStack() {
        mini = -1;
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mini = val;
        }
        else{
            if(val>=mini){
                s.push(val);
            } else {
                long long data= 2LL* val-mini;
                s.push(data);
                mini = val;
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        long long curr= s.top();
        s.pop();
        if(curr<mini) mini= 2LL* mini - curr;
    }
    
    int top() {
        if(s.empty()) return -1;
        if(s.top()<mini) return mini;
        return s.top();
    }
    
    int getMin() {
        if(s.empty()) return -1;
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */