class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size()-1;
        vector<int> curr(4, 1e9);
        vector<int> next(4, 1e9);
        next[0] = 0; next[1] = 0; next[2] = 0; next[3] = 0;

        for(int pos=n-1; pos>=0; pos--){
            for(int lane=1; lane<=3; lane++){
                if(obstacles[pos+1]!=lane){
                    curr[lane] = next[lane];
                }
                else{ //sideways-jump
                    int ans = 1e9;
                    for(int k=1; k<=3; k++){
                        if(k!=lane && obstacles[pos]!=k)
                            ans = min(ans, 1 + next[k]);
                    }
                    curr[lane] = ans;
                }
            }
            next = curr;
        }
        return min(curr[2], 1 + min(curr[1], curr[0]));
    }
};