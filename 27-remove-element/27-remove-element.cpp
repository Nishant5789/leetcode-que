class Solution {
public:
    int removeElement(vector<int>& n, int val) {
        if(n.size() == 0)
            return 0;
        else
            if(n.size() == 1)
            {
                if(n[0] == val)
                    return 0;
                else
                    return 1;
            }
        int i = 0, j = 1;
        int flag = count(n.begin(), n.end(), val);
        while(j < n.size())
        {
            if(n[i] == val && n[j] == val)
               j++;
            else
                if(n[i] == val)
                {
                    swap(n[i], n[j]);
                    i++;j++;
                }
            else
                {i++;j++;} 
        }
        
        return n.size() - flag;
    }
};