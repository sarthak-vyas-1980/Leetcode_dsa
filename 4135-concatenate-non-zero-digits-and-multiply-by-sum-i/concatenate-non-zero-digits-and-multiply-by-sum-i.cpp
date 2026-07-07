class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        long long num = 0, sum = 0;

        for(char c: s){
            if(c != '0') num = num * 10 + (c - '0');
            sum += c - '0';
        }
        return sum * num;
    }
};