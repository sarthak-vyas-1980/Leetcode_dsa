class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> powerOfTwo;
        int ans = 0;

        for(int num: nums){
            powerOfTwo[num]++;
        }
        
        for(auto row: powerOfTwo){
            long long number = row.first;
            int count = 0;

            if(number == 1){
                count = powerOfTwo[number];
                ans = max(ans, count&1 ? count : count-1);
                continue;
            }
            
            bool attainedPeak = false;
            while(powerOfTwo.count(number)){
                if(powerOfTwo[number] >= 2) count += 2;
                else if(powerOfTwo[number] == 1){
                    ans = max(ans, count + 1);
                    attainedPeak = true;
                    break;
                }
                if (number > 31622) break; // optimization!!!
                number *= number;
            }
            if(!attainedPeak) ans = max(ans, count-1);
        }
        return ans;
    }
};