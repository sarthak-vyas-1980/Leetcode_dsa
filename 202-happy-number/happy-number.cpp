class Solution {
    bool solve(int n, unordered_set<int> s){
        if(n == 1) return true;
        int sum = 0;
        while(n != 0){
            sum += pow(n%10, 2);
            n /= 10;
        }
        if(s.find(sum) == s.end()){
            s.insert(sum);
            return solve(sum, s);
        }
        else{
            return false;
        }
    }
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        return solve(n, s);
    }
};