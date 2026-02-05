class Solution {
    void dfs(int row, int col, int n, int m, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<vector<int>> &low, vector<vector<int>> &disc, int &timer, bool &isBridge, int parentX, int parentY){
            int arr[4][2] = {{1,0}, {-1,0}, {0,-1}, {0,1}};
            low[row][col] = timer;
            disc[row][col] = timer++;
            vis[row][col] = 1;
            int child = 0;
            for(int delcol = 0; delcol <4; delcol++) {
                int nrow = row + arr[delcol][0];
                int ncol = col + arr[delcol][1];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                    if(parentX==nrow && parentY==ncol) continue;
                    if(vis[nrow][ncol]==0){
                        dfs(nrow, ncol, n, m, grid, vis, low, disc, timer, isBridge, row, col);
                        child++;
                        low[row][col] = min(low[row][col], low[nrow][ncol]);
                        if(low[nrow][ncol] >= disc[row][col] && parentX!=-1 && parentY!=-1) isBridge = true;
                    }
                    else {
                        low[row][col] = min(low[row][col], disc[nrow][ncol]);
                    }
                }
            }
            if(parentX==-1 && parentY==-1 && child>1) isBridge = true;
    }
    public:
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0, timer = 0;
        bool isBridge = false;
        //grid itself will act for visited as we'll convert it into 0 from 1 and it won't be accessed again
        vector<vector<int>> low(n, vector<int>(m, 0));
        vector<vector<int>> disc(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){ 
                    if(count==1) return 0; // more than 1 island so already disconnected
                    count++;
                    dfs(i, j, n, m, grid, vis, low, disc, timer, isBridge, -1, -1);
                }
            }
        } //As you can see the example1 that for the worst case, 
        // no more than two days will be needed to disconnect the island.
        if(count==0) return 0; //no island found
        if(isBridge) return 1;
        if(timer==1) return 1; //just one element in the island
        return 2;
    }
};








