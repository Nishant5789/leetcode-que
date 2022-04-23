class Solution {
public:
    int removeDuplicates(vector<int>& num) {
        int i = 0, j = 1, index = 0, last, count = 1;
        last = num[num.size() - 1];
        while(j != num.size())
        {
            if(num[i] == num[j])
            {   
                i++;j++;
            }
            else{
                count++;
                num[index++] = num[i];
                i++;j++;
            }
        }
        num[index] = last;
        return count;
    }
};