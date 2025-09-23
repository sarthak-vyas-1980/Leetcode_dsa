class Solution {
    vector<int> nextSmallest(vector<int> &heights){
        int n= heights.size();
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=n-1; i>=0; i--){
            while(s.top()!=-1 && heights[s.top()]>= heights[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> prevSmallest(vector<int> &heights){
        int n= heights.size();
        stack<int> s;
        vector<int> ans(n);
        s.push(-1);
        for(int i=0; i<n; i++){
            while(s.top()!=-1 && heights[s.top()]>= heights[i]){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int area= 0;
        vector<int> next= nextSmallest(heights);
        vector<int> prev= prevSmallest(heights);

        for(int i=0; i<n; i++){
            if(next[i]==-1) next[i]=n;
            int l= heights[i];
            int b= next[i]- prev[i]-1;
            area= max(area, l*b); 
        }
        return area;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row= matrix.size();
        int col= matrix[0].size();
        int area= 0;
        vector<int> heights(col, 0);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if (matrix[i][j] == '1') {
                    heights[j] += 1;    // accumulate heights
                } else {
                    heights[j] = 0;     // reset when '0'
                }
            }
            area = max(area, largestRectangleArea(heights));
        }
        return area;
    }
};