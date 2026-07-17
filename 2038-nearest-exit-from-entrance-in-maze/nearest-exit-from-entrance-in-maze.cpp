class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size(), n = maze[0].size();
        int arr[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int ans = 1;

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                pair<int, int> temp = q.front();
                q.pop();

                for(int j=0; j<4; j++){
                    int x = temp.first + arr[j][0];
                    int y = temp.second + arr[j][1];

                    if(x<0 || x>=m || y<0 || y>=n) continue;
                    if((x==0 || x==m-1 || y==0 || y==n-1) && maze[x][y] == '.') return ans;
                    if(maze[x][y] == '.'){
                        q.push({x, y});
                        maze[x][y] = '+';
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};