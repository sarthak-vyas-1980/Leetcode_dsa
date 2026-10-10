class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int countOpen = 0, countClosed = 0;
        for(char ch : s){
            if(ch == '('){
                countOpen++;
                if(countOpen != 1) ans += ch;
            }
            else if(ch == ')'){
                countClosed++;
                if(countOpen == countClosed){
                    countClosed = 0;
                    countOpen = 0;
                }
                else ans += ch;
            }
        }
        return ans;
    }
};