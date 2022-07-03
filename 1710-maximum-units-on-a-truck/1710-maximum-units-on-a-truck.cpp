
bool cmp(pair<int,int> a, pair<int,int> b)
{
        if(a.second!=b.second)
            return a.second>b.second;
        else
            return a.first<b.first;
}
class Solution {

    int fun(int a, int b, int count, int truckSize, int& box_fill)
    {
        int left=truckSize-box_fill;
        // cout << left << " " << "box_fill" << box_fill;
        if(a<=left)
        {
            box_fill+=a;
            return b*a;
        }
        else
        {
            box_fill+=left;
            return left*b;
        }
            
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> mp;
        int r=boxTypes.size(), c=boxTypes[0].size();
        for(int i=0; i<r; i++)
        {
            mp.push_back(make_pair(boxTypes[i][0],boxTypes[i][1]));
        }
        sort(mp.begin(),mp.end(),cmp);
        int count=0, box_fill=0;
        for(auto &i: mp)
        {
            
            // cout << fun(i.first, i.second, count, truckSize, box_fill) << " "<<endl;
            count+=fun(i.first, i.second, count, truckSize, box_fill);
            if(count==truckSize)
                break;
        }
        return count;
    }
};