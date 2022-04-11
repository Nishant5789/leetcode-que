class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minnium = INT_MAX, maximum = 0;
        
       for(int i = 0; i < prices.size(); i++)
       {
           minnium = min(minnium, prices[i]);
           maximum = max(maximum, prices[i] - minnium);
       }
        return maximum;
    } 
};