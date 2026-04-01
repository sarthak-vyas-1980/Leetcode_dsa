class Solution {
    void recursion(int sum,int n,vector<int>& candidates,vector<vector<int>>& ans,vector<int> path, int start){
        
        if(sum==n){
            ans.push_back(path);
            return ;
        }
        if(sum>n) return;

        for(int j=start; j<candidates.size(); j++){
            if(sum+candidates[j] <= n){
                path.push_back(candidates[j]);                              //include
                recursion(sum + candidates[j], n, candidates, ans, path, j+1);
                while(j+1<candidates.size() && candidates[j] == candidates[j+1]) j++;
                path.pop_back();                                            //exclude
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>path;
        sort(candidates.begin(), candidates.end());
        recursion(0, target, candidates, ans, path, 0); 
        return ans;  
    }
};