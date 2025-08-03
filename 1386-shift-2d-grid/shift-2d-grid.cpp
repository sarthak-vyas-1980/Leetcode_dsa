class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;

        while(count<k){
            vector<int>help;
            help.push_back(grid[r-1][c-1]);

            for(int i=0; i<r ;i++){
                for(int j=0; j<c ;j++){
                    if(i==r-1 && j==c-1) continue;
                    help.push_back(grid[i][j]);
                }
            }
            int k=0;
            for(int i=0; i<r ;i++){
                for(int j=0; j<c ;j++){
                    grid[i][j]=help[k++];
                }
            }
            count++;
        }
        return grid;
    }
};