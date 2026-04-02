class Solution {
public:
    int maximum69Number (int num) {
        int reverse = 0;
        int n = num;
        while(n!=0){
            int digit = n%10;
            reverse = reverse*10 + digit;
            n = n/10;
        }
        int ans = 0;
        bool flag = true;
        while(reverse!=0){
            int digit = reverse%10;
            if(flag && digit == 6){
                digit = 9;
                flag = false;
            }
            ans = ans*10 + digit;
            reverse /= 10;
        }
        return ans;
    }
};