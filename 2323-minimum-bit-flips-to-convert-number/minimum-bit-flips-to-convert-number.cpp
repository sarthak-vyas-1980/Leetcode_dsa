class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal, count = 0;
        while(n){
            n = n & (n-1);
            count++;
        }
        return count;
    }
};