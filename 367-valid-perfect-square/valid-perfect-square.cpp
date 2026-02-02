class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int i=0, j=num;
        long long int mid = i+(j-i)/2;
        while(i<=j){
            long long int mul = mid*mid;
            if(mul==num) return true;
            else if(mul<num) i=mid+1;
            else j=mid-1;
            mid = i+(j-i)/2; 
        }
        return false;
    }
};