class Solution {
public:
    int fib(int n) {
       int prev1 = 0;
       int prev2 = 1;
       for(int i=0; i<n; i++){
           int ans= prev1 + prev2;
           prev2 = prev1;
           prev1 = ans;
       }
       return prev1;
    }
};