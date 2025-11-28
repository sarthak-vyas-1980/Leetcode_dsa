class Solution {
    bool isPresent(string s, int j, unordered_map<char, int> m){
        for(int k=j; k<s.length(); k++){
            m[s[k-j]]--;
            m[s[k]]++;
            bool check = true;
            for(auto i: m){
                if(i.second > 1) check = false;
            }
            if(check) return true;
        }
        return false;
    }
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_map<char, int> m;
        m[s[0]]++;
        int ans = 1;
        bool check = true;
        for(int j=1; j<s.length(); j++){
            m[s[j]]++;
            if(check && m[s[j]]==1) ans++;
            else if(isPresent(s, j+1, m)){
                ans++;
                check = false;
            }  
            else break;
        }
        return ans;
    }
};