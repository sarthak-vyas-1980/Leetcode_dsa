class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<int> ans;
        int count=0,total=row*col;
        int startRow=0;
        int endRow=row-1;
        int startCol=0;
        int endCol=col-1;

        while(count<total){
            for(int i=startCol;count<total && i<=endCol; count++,i++){
                ans.push_back(matrix[startRow][i]);
            }
            startRow++;
            for(int i=startRow;count<total && i<=endRow; count++,i++){
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;
            for(int i=endCol;count<total && i>=startCol; count++,i--){
                ans.push_back(matrix[endRow][i]);
            }
            endRow--;
            for(int i=endRow;count<total && i>=startRow; count++,i--){
                ans.push_back(matrix[i][startCol]);
            }
            startCol++;
        }
        return ans;
    }
};