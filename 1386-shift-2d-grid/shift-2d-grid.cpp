class Solution {
    vector<int> shift(vector<int>& help, int k){
        vector<int> ansHelp(help.size());
        for(int j=0; j<help.size(); j++){
            ansHelp[(j+k)%(help.size())] = help[j];
        }
        return ansHelp;
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        if(k==0) return grid;
        int r=grid.size();
        int c=grid[0].size();

        vector<int>help;
        //help.push_back(grid[r-1][c-1]);(for once!!!)

        for(int i=0; i<r ;i++){
            for(int j=0; j<c ;j++){
                //if(i==r-1 && j==c-1) continue;
                help.push_back(grid[i][j]);
            }
        }
        help=shift(help, k);
                   
        int n=0;
        for(int i=0; i<r ;i++){
            for(int j=0; j<c ;j++){
                grid[i][j]=help[n++];
            }
        }
        return grid;
    }
};