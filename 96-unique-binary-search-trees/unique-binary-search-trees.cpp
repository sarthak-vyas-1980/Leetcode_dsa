class Solution {
public:
    int numTrees(int n) {
        int ans = 1;
        for(int i=1; i<=n; i++){
            ans = ans * (4 - 6.0/(i+1));
        }
        return ans;
    }
};