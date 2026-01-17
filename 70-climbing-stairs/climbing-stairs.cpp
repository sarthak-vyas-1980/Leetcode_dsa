class Solution {
public:
    int climbStairs(int n) {
        int prev1=1;
        int prev2=0;
        for(int i=1; i<=n; i++){
            int ans = prev1 + prev2;
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
};