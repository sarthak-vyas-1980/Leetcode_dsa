class Solution {
public:
    int myAtoi(string s) {
        long num = 0;
        int sign = 1;
        bool isStarted = false;

        for(int i=0; i<s.length(); i++){
            if(!isdigit(s[i]) && isStarted) break;

            else if(s[i] == ' ' && !isStarted) continue;

            else if((s[i] == '+' || s[i] == '-') && !isStarted){
                sign = s[i]=='+' ? 1 : -1;
                isStarted = true;
            }

            else if(isdigit(s[i])){
                num = (num * 10) + (s[i]-'0');
                if(num * sign >= INT_MAX) return INT_MAX;
                if(num * sign <= INT_MIN) return INT_MIN;
                isStarted = true;
            }
            else break;
        }
        return num * sign;
    }
};