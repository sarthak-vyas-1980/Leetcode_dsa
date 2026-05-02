class MyQueue {
    stack<int> input, output;
    //input contains reversed order of queue from recently added elements
    //output contains actual order of it but for older elements, so if it empties out -> transfer from input to output
public:
    void push(int x) {
        input.push(x);
    }

    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};