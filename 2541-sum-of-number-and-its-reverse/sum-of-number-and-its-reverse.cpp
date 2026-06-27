class Solution {
    int reverse(int n){
        int num = 0;
        while(n){
            num = num * 10 + n%10;
            n /= 10; 
        }
        return num;
    }
public:
    bool sumOfNumberAndReverse(int num) {
        
        for(int i=0; i<=num; i++){
            if(i + reverse(i) == num) return true;
        }
        return false;
    }
};