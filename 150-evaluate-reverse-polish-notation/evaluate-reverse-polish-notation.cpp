class Solution {
    bool isdigit(string str){
        if(str == "+" || str == "-" || str == "*" || str == "/") return false;
        return true;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string token: tokens){
            if(isdigit(token)){
                s.push(stoi(token));
            }
            else{
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                if(token == "+" || token == "-"){
                    s.push(token=="+" ? first+second : first-second);
                }
                else if(token == "*") s.push(first * second);
                else s.push(first / second);
            }
        }
        return s.top();
    }
};