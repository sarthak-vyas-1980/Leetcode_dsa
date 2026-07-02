class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size(); 
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        int arr[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        dist[0][0] = grid[0][0];

        while(!q.empty()){
            pair<int, int> temp = q.top();
            q.pop();

            for(int k=0; k<4; k++){
                int x = temp.first + arr[k][0];
                int y = temp.second + arr[k][1];

                if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size()) continue;
                if(dist[x][y] > dist[temp.first][temp.second] + grid[x][y]){
                    dist[x][y] = dist[temp.first][temp.second] + grid[x][y];
                    q.push({x, y});
                }
            }
        }
        return dist[m-1][n-1] < health;
    }
};