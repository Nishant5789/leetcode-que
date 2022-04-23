class Solution {
public:
    void moveZeroes(vector<int>& num) {
    int i = 0;
    int j = i + 1;
        while(j != num.size())
        {
            if(num[i] == 0 && num[j] == 0){
                j++;
            }
            else
            {
                if(num[i] == 0)
                {
                    swap(num[i], num[j]);
                    i++; 
                    j++;
                }
                else
                    {i++;
                    j++;}
            }
        }
    }
};