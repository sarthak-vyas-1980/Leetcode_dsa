class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int MOD = 1e9 + 7;
        vector<int> prev(target+1, 0);
        vector<int> curr(target+1, 0);
        prev[0] = 1;

        for(int dice=1; dice<=n; dice++){
            for(int t=1; t<=target; t++){
                long long ans = 0;
                for(int i=1; i<=k; i++){
                    if(t-i>=0) ans = (ans + prev[t-i]) % MOD;
                    else break;
                }
                curr[t] = ans;
            }
            prev = curr;
        }
        return curr[target];
    }
};