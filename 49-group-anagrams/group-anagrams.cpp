class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.size()==0) return ans;
        if(strs.size()==1 && strs[0]==""){
            ans.push_back(strs);
            return ans;
        }
        unordered_map<string, vector<string>> map;
        for(int i=0; i<strs.size(); i++){
            string s1 = strs[i];
            sort(strs[i].begin(), strs[i].end());
            map[strs[i]].push_back(s1);
        }
        for(auto i: map){
            ans.push_back(i.second);
        }
        return ans; 
    }
};