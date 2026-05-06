class Solution {
    void solve(vector<vector<int>>& image, int sr, int sc, int val, int color){
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int arr[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            image[p.first][p.second] = color;
            for(int i=0; i<4; i++){
                int row = p.first + arr[i][0];
                int col = p.second + arr[i][1];
                if(row>=0 && row<image.size() && col>=0 && col<image[0].size() && image[row][col]==val){
                    q.push({row, col});
                }
            }

        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        solve(image, sr, sc, image[sr][sc], color);
        return image;
    }
};