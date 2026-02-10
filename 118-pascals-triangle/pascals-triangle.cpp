class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0; i<numRows; i++){
            long long pass = 1;
            vector<int> path;
            for(int j=0; j<=i; j++){
                path.push_back(pass);
                pass = pass*(i-j)/(j+1);
            }
            ans.push_back(path);
        }
        return ans;
    }
};

