class Solution {
public:
    int binaryGap(int n) {
        int count = INT_MIN;
        int ans = 0;
        while(n!=0){
            char ch = n%2 + '0';
            if(ch == '1') {
                ans = max(ans, count);
                count = 1;
            } else{
                count++;
            } 
            n /= 2;
        }
        return ans;
    }
    // int binaryGap(int n) {.............................
    //     string s;
    //     while(n!=0){
    //         s.push_back(n%2 + '0');
    //         n /= 2;
    //     }
    //     int lastIndex = -1e9;
    //     int ans = 0;
    //     for(int i=s.length()-1; i>=0; i--){
    //         if(s[i] == '1') {
    //             ans = max(ans, lastIndex-i);
    //             lastIndex = i;
    //         }
    //     }
    //     return ans <= -1e9 ? 0 : ans;
    // }
};