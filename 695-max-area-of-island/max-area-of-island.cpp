class Solution {
    int traverse(vector<vector<int>>& grid, int (&arr)[4][2], int i, int j){
        int count = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;

        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();
            count++;

            for(int k=0; k<4; k++){
                int x = temp.first + arr[k][0];
                int y = temp.second + arr[k][1];

                if(x>=0 && x<grid.size() && y>=0 && y<grid[x].size() && grid[x][y]){
                    q.push({x, y});
                    grid[x][y] = 0;
                }
            }
        }
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = INT_MIN;
        int arr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]) ans = max(ans, traverse(grid, arr, i, j));  
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};