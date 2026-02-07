class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<2) return 0;
        int ans = 0;
        vector<int> prev_max(n);
        vector<int> next_max(n);
        prev_max[0] = height[0];
        next_max[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            prev_max[i] = max(height[i], prev_max[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            next_max[i] = max(height[i], next_max[i+1]);
        }
        for(int i=0; i<n; i++){
            int mini = min(prev_max[i], next_max[i]);
            if(mini>height[i]) ans += mini-height[i];
        }
        return ans;
    }
};