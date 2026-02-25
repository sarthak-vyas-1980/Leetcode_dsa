class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<pair<int, int>> s;
        s.push({-1,-1});
        for(int i=temperatures.size()-1; i>=0; i--){
            if(s.top().first == -1) ans[i] = 0;
            else{
                int i1 = s.top().second;
                while(s.top().first != -1 && temperatures[i] >= s.top().first){
                    s.pop();
                }
                int i2 = s.top().second;
                ans[i] = s.top().first == -1 ? 0 : i2-i1+1;
            }
            s.push({temperatures[i], i});
        } 
        return ans;
    }
};