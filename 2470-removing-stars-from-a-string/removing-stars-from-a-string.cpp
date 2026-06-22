class Solution {
public:
    string removeStars(string s) {
        stack<int> st;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '*') st.pop();
            else st.push(s[i]);
        }

        int i = st.size() - 1;
        string ans = s.substr(0, st.size());
        while(!st.empty()){
            int top = st.top();
            st.pop();
            ans[i--] = top;
        }
        return ans;
    }
};