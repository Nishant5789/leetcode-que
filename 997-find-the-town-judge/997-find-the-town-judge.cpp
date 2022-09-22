class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>in(n+1,0);
        for(auto i:trust)
        {
            in[i[1]]++;
            in[i[0]]--;
        }
        for(int i=1;i<=n;i++)
        {
            if(in[i]==n-1)
            {
                return i;
            }
        }
        return -1;
    }
};