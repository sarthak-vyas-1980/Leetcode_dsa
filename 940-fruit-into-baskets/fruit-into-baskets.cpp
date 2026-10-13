class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int count1 = 0, count2 = 0, ans = 0;
        int type1 = -1, type2 = -1;
        
        for(int j=0; j< fruits.size(); j++){
            if(type1 == -1 || fruits[j] == type1){
                type1 = fruits[j];
                count1++;
            }
            else if(type2 == -1 || fruits[j] == type2){
                type2 = fruits[j];
                count2++;
            }
            else{
                while(count1 > 0 && count2 > 0){
                    fruits[i++] == type1 ? count1-- : count2--;
                }
                if(count1 == 0){
                    count1++;
                    type1 = fruits[j];
                }
                else{
                    count2++;
                    type2 = fruits[j];
                }
            }
            ans = max(ans, count1 + count2);
        }
        return ans;
    }
};