class Solution {
public:
    int search(vector<int>& num, int target) {
        int left = 0, right = num.size() - 1, middle;
        while(left <= right)
        {
            middle = left + (right - left) / 2;
            if(num[middle] == target)
                return middle;
            else
                if(num[middle] > target)
                    right = middle - 1;
            else
                left = middle + 1;
        }
        return -1;
    }
};