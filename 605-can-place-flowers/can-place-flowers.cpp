class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;
        
        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i] == 1){
                i++;
            }
            else{
                if((i+1 < flowerbed.size() && flowerbed[i+1] == 0) || i == flowerbed.size()-1){
                    n--;
                    i++;
                }
            }
            if(n == 0) return true;
        }
        return false;
    }
};