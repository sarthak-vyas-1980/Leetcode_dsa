class Solution {
    int sequentialScanOnCol(vector<vector<int>>& mat, int n, int mid){
        int maxi = 0;
        for(int i=1; i<n; i++){
            if(mat[maxi][mid] < mat[i][mid]) maxi = i;
        }
        return maxi;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            int ind = sequentialScanOnCol(mat, n, mid);
            int left = mid-1 >= 0 ? mat[ind][mid-1] : -1;
            int right = mid+1 < m ? mat[ind][mid+1] : -1;
            if(mat[ind][mid] > left && mat[ind][mid] > right) return {ind, mid};
            else if(mat[ind][mid] < left) high = mid - 1;
            else low = mid + 1;
        }
        return {-1, -1};
    }
};