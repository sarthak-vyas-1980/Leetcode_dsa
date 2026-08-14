class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        for(int i=1; i<=n; i++){
            if(i%2 == 0) ans[i] = ans[i/2];
            else ans[i] = ans[i/2] + 1;
        }
        return ans;



        // vector<int> ans;
        // for(int i=0; i<=n; i++){
        //     int count = 0;
        //     int N = i;
        //     while(N){
        //         N = N & (N-1);
        //         count++;
        //     }
        //     ans.push_back(count);
        // }
        // return ans;
    }
};