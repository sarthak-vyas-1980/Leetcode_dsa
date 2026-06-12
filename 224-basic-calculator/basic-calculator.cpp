class Solution {
public:
    int calculate(string s) {
        long long curr = 0, ans = 0;
        int sign = +1;
        stack<int> st;

        for (int i=0; i<s.length(); i++) {
            if (isdigit(s[i])) { 
                curr = (curr * 10) + (s[i] - '0');
            }
            else if(s[i] == '+' || s[i] == '-'){
                ans += sign * curr;
                curr = 0;
                sign = s[i]=='+' ? 1 : -1;
            }
            else if(s[i] == '('){
                st.push(ans);
                st.push(sign);
                
                ans = 0;
                sign = +1;
            }
            else if(s[i] == ')'){
                ans += sign * curr;
                curr = 0;

                ans = ans * st.top(); // Adding sign to ans after bracket opens
                st.pop();
                ans += st.top(); // Adding calc prior to bracket with it's ans
                st.pop();
            }
            // else space-ignore.
        }
        return ans + (sign * curr);
    }
};