class Solution {

    void solve(vector<string>& ans,string path,string digits,unordered_map<char,list<char>>m,int i){

        if(i==digits.length()){
            ans.push_back(path);
            return ;
        }
        for(auto j: m[digits[i]]){
            path.push_back(j);
            solve(ans,path,digits,m,i+1);
            path.pop_back();
        }
    }
public:
    
    vector<string> letterCombinations(string digits) {
        
        unordered_map<char,list<char>>m;
        m['2']={'a','b','c'};
        m['3']={'d','e','f'};
        m['4']={'g','h','i'};
        m['5']={'j','k','l'};
        m['6']={'m','n','o'};
        m['7']={'p','q','r','s'};
        m['8']={'t','u','v'};
        m['9']={'w','x','y','z'};

        string path;
        vector<string>ans;
        if(digits.length()==0)return ans;
        solve(ans,path,digits,m,0);
        return ans;
    }
};