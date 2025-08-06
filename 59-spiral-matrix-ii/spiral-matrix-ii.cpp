class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int count=0,total=n*n;
        int startRow=0;
        int endRow=n-1;
        int startCol=0;
        int endCol=n-1;
        int j=1;

        while(count<total){
            for(int i=startCol;count<total && i<=endCol; count++,i++){
                ans[startRow][i]=j++;
            }
            startRow++;
            for(int i=startRow;count<total && i<=endRow; count++,i++){
                ans[i][endCol]=j++;
            }
            endCol--;
            for(int i=endCol;count<total && i>=startCol; count++,i--){
                ans[endRow][i]=j++;
            }
            endRow--;
            for(int i=endRow;count<total && i>=startRow; count++,i--){
                ans[i][startCol]=j++;
            }
            startCol++;
        }
        return ans;
    }
};