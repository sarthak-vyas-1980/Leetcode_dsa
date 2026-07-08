class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int arr[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        int count = 0;
        queue<pair<int, int>> q;

        for(int i=0; i<grid.size(); i++){
            bool flag = false;
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]){
                    q.push({i, j});
                    grid[i][j] = -1;
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }   

        while(!q.empty()){
            pair<int, int> temp = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int x = temp.first + arr[i][0];
                int y = temp.second + arr[i][1];

                if(x>=0 && x<grid.size() && y>=0 && y<grid[x].size()){
                    if(grid[x][y] == 1){
                        q.push({x, y});
                        grid[x][y] = -1;
                    }
                    else if(grid[x][y] == 0) count++;
                }
                else count++;
            }
        }
        return count;
    }
};