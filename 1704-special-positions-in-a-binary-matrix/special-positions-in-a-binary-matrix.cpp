class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {    
        int m = mat.size();
        int n = mat[0].size();  
        unordered_map<int, vector<pair<int, int>>> row;
        unordered_map<int, vector<pair<int, int>>> col;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    row[i].push_back({i, j});
                    col[j].push_back({i, j});
                }
            }
        }
        int count = 0;
        for(auto i:row){
            if(i.second.size() == 1){
                int column = i.second[0].second;
                if(col[column].size() == 1 && col[column] == i.second) count++;
            }
        }
        return count;
    }
};