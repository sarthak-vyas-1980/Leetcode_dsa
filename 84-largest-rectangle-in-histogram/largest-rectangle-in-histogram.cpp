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
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        int area= INT_MIN;
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
};