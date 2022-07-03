
class Solution {
public:
    const unsigned int M = 1000000007;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts)
    {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int maxi1=horizontalCuts[0], maxi2=verticalCuts[0];
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        for(int i=0; i<horizontalCuts.size()-1; i++)
        {
            maxi1=max(maxi1,abs(horizontalCuts[i]-horizontalCuts[i+1]));
        }
        for(int i=0; i<verticalCuts.size()-1; i++)
        {
            maxi2=max(maxi2,abs(verticalCuts[i]-verticalCuts[i+1]));
        }
        return (1LL*maxi1*maxi2)%M;   
    }
};