class Solution {
    bool isPossible(vector<vector<int>>& matrix, int mid, int n, int k){
        int row = n-1, col = 0;
        int count = 0;

        while(row >=0 && col < n){
            if(matrix[row][col] <= mid){
                count += row + 1;
                col++;
            }
            else row--;
        }
        return count < k; 
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0], high = matrix[n-1][n-1];

        while(low < high){
            int mid = low + (high - low)/2;
            if(isPossible(matrix, mid, n, k)) low = mid + 1; //Checks if mid has lesser elements smaller than k
            else high = mid;
        }
        return low;
    }
};