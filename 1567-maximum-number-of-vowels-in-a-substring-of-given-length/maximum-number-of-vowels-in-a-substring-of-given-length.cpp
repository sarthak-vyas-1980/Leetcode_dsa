class Solution {
    bool check(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int ans = 0, count = 0;
        for(int i=0; i<k; i++){
            if(check(s[i])) count++;
        }

        ans = count;
        for(int i=k; i<s.length(); i++){
            if(check(s[i])) count++;
            if(check(s[i-k])) count--;
            ans = max(ans, count);
        }
        return ans;
    }
};