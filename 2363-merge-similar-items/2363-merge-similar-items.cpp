class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
               map<int,int> m; ;
        for(int i=0;i<items1.size();i++)
        {
            if(m.find(items1[i][0])!=m.end())
            {
                m[items1[i][0]]=(m.find(items1[i][0])->second) + items1[i][1];
                continue;
            }
                m[items1[i][0]]=items1[i][1];
        }
         for(int i=0;i<items2.size();i++)
        {
            if(m.find(items2[i][0])!=m.end())
            {
                m[items2[i][0]]=(m[items2[i][0]] + items2[i][1]);
                continue;
            }
                m[items2[i][0]]=items2[i][1];
         }
        vector<vector<int>> v(m.size(), vector<int> (2,0));int i=0;
        for(auto itr : m)
        {
           v[i][0]=itr.first;
            v[i][1]=itr.second;
            i++;
        }
        return v;
 
         
    }
};