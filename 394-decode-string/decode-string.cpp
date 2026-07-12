class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> stt;
        int i = 0, num = 0;
        string ans = "";
        
        while(i<s.length()){
            if(isalpha(s[i])) ans.push_back(s[i]);

            else if(isdigit(s[i])) num = num * 10 + (s[i] - '0');

            else if(s[i] == '['){
                st.push(ans);
                stt.push(num);
                ans = "";
                num = 0;
            }

            else if(s[i] == ']'){
                string temp = ans; 
                for(int k=1; k<stt.top(); k++){
                    ans += temp;
                }
                ans = st.top() + ans;
                st.pop();
                stt.pop();
            }
            i++;
        }
        return ans;
    }
};