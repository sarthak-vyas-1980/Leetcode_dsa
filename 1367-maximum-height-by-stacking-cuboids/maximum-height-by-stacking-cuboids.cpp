class Solution {
    bool check(vector<int> base, vector<int> newBox){
        if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2]) return true;
        return false;
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        for(auto &i: cuboids){
            sort(i.begin(), i.end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);

        // for(int i=n-1; i>=0; i--){
        //     for(int prev=i-1; prev>=-1; prev--){
        //         int take = 0;
        //         if(prev==-1 || check(cuboids[i], cuboids[prev])) take = cuboids[i][2] + next[i+1];
        //         int notTake = next[prev+1];
        //         curr[prev+1] = max(take, notTake);
        //     }
        //     next = curr;
        // }
        for(int i=n-1; i>=0; i--){
            for(int prev=-1; prev<n; prev++){
                int take = 0;
                if(prev==-1 || check(cuboids[i], cuboids[prev])) take = cuboids[i][2] + curr[i+1];
                int notTake = curr[prev+1];
                curr[prev+1] = max(take, notTake);
            }
        }
        return curr[0];
    }
};