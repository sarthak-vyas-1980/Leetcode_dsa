class Solution {
    static bool cmp(int a, int b){
        return a > b;
    } 
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), cmp); 

        int h = 0;
        for(int i=0; i<citations.size(); i++){
            if(citations[i] >= i + 1) h = i + 1;
            else break;
        }
        return h;
    }
};