class Solution {
    int traverse(vector<vector<int>>& grid, int (&arr)[4][2], int i, int j){
        int count = -1;
        queue<pair<int, int>> q;
        q.push({i, j});

        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int z=0; z<size; z++){
                pair<int, int> temp = q.front();
                q.pop();
                flag = true;

                for(int k=0; k<4; k++){
                    int x = temp.first + arr[k][0];
                    int y = temp.second + arr[k][1];

                    if(x>=0 && x<grid.size() && y>=0 && y<grid[x].size() && grid[x][y]==1){
                        q.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
            if(flag) count++;
        }
        return count;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0, fresh = 0;
        int arr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) fresh++;   
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }

        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int z=0; z<size; z++){
                pair<int, int> temp = q.front();
                q.pop();

                for(int k=0; k<4; k++){
                    int x = temp.first + arr[k][0];
                    int y = temp.second + arr[k][1];

                    if(x>=0 && x<grid.size() && y>=0 && y<grid[x].size() && grid[x][y]==1){
                        q.push({x, y});
                        flag = true;
                        fresh--;
                        grid[x][y] = 2;
                    }
                }
            }
            if(flag) ans++;
        }
        return fresh ? -1 : ans ; 
    }
};