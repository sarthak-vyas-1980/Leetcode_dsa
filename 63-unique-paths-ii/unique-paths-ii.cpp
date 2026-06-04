class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        if(m==1 && n==1) return !obstacleGrid[0][0];

        vector<long long> curr(n, 0), next(n, 0);
        curr[n-1] = 1;

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(obstacleGrid[i][j]) continue;
                if(i+1<m && !obstacleGrid[i+1][j]){
                    curr[j] += next[j];
                }
                if(j+1<n && !obstacleGrid[i][j+1]){
                    curr[j] += curr[j+1];
                }
            }
            next = curr;
            fill(curr.begin(), curr.end(), 0);
        }
        return next[0];
    }
};