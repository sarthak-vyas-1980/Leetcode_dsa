class Solution {
private:
    void reverse(vector<int>& arr){
        int s=0;
        int e=arr.size()-1;
        while(s<=e){
            swap(arr[s++],arr[e--]);
        }
    }
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int i=digits.size()-1;
        vector<int>ans;
        ans.push_back((digits[i]+1)%10);
        carry=(digits[i--]+1)/10;
        while(i>=0){
            int sum=carry+digits[i];
            int digit=sum%10;
            ans.push_back(digit);
            carry=sum/10;
            i--;
        }
        while(carry!=0){
            int sum=carry;
            int digit=sum%10;
            ans.push_back(digit);
            carry=sum/10;
        }
        reverse(ans);
        return ans;
    }
};