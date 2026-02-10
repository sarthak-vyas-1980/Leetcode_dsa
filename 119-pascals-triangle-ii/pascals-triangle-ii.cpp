class Solution {
public:
    vector<int> getRow(int rowIndex){
        long long pass = 1;
        vector<int> path;
        for(int j=0; j<=rowIndex; j++){
            path.push_back(pass);
            pass = pass*(rowIndex-j)/(j+1);
        }
        return path;
    }
};