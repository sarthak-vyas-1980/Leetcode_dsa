class Solution {
public:
    bool hasAlternatingBits(int n) {
        string ans;
        while(n!=0){
            ans.push_back(n%2 + '0');
            n /= 2;
        }
        for(int i=1; i<ans.length(); i++){
            if(ans[i-1] == ans[i]) return false;
        }
        return true;
    }
};