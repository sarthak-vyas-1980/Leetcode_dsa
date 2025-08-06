class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int>ans;
        for(int i=0; i<matrix[0].size(); i++){
            for(int j=matrix.size()-1; j>=0; j--){
                ans.push_back(matrix[j][i]);
            }
        }
        int k=0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                matrix[i][j]=ans[k++];
            }
        }
    }
};