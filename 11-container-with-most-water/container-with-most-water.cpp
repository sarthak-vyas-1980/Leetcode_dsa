class Solution {
public:
    int maxArea(vector<int>& height) {
        int s=0, e=height.size()-1;
        int ans = 0;
        while(s<e){
            int area = (e-s)*min(height[s], height[e]);
            ans = max(ans, area);
            height[s]>height[e] ? e-- : s++;
        }
        return ans;
    }
};