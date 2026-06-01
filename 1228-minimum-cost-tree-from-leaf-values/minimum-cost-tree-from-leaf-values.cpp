class Solution {
    int solve(vector<int>& arr, map<pair<int, int>, int>& map, int start, int end, vector<vector<int>>& dp){
        if(start >= end) return 0;
        if(dp[start][end] != -1) return dp[start][end];

        int ans = INT_MAX;
        for(int i=start; i<end; i++){
            ans = min(ans, map[{start, i}] * map[{i+1, end}] + solve(arr, map, start, i, dp) + solve(arr, map, i+1, end, dp));
        }
        return dp[start][end] = ans;
    }
public:
    int mctFromLeafValues(vector<int>& arr) {
        int size = arr.size();
        vector<vector<int>> dp(size+1, vector<int>(size+1, -1));
        map<pair<int, int>, int> map;

        for(int i=0; i<size; i++){
            map[{i, i}] = arr[i];
            for(int j=i+1; j<size; j++){
                map[{i, j}] = max(arr[j], map[{i, j-1}]);
            }
        }
        return solve(arr, map, 0, size-1, dp);
    }
};