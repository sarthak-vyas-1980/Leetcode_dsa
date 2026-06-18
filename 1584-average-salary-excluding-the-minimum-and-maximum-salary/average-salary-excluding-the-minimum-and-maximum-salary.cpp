class Solution {
public:
    double average(vector<int>& salary) {
        if(salary.size() <= 2) return 0.0;

        int mini = INT_MAX, maxi = INT_MIN;
        int sum = 0;

        for(int sal: salary){
            sum += sal;
            mini = min(mini, sal);
            maxi = max(maxi, sal);
        } 
        double ans = (sum - mini - maxi) * 1.0 / (salary.size() - 2);
        return ans;
    }
};