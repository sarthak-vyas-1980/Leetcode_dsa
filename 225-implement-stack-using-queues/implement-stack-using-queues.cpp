class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=1; i<q.size(); i++){
            int val = q.front();
            q.pop();
            q.push(val);
        }
    }
    
    int pop() {
        if(q.empty()) return -1;
        int ans = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */