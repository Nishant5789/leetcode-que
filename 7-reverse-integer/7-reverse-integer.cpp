class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0){
            int digit = x%10;
            if(ans >= INT_MIN/10 && ans <= INT_MAX/10){
            ans = ans*10 + digit;
            }
            else{
                break;
            }
            x = x/10;
            
        }
        if(x == 0) return ans;
        else return false;
        
    }
};