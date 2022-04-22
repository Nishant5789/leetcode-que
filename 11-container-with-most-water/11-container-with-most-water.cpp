class Solution {
public:
    int maxArea(vector<int>& height) {
        int j, i = 0, max_area = 0;
        j = height.size() - 1;
        while(i < j)
        {
            int lh = height[i];
            int rh = height[j];
            int min_h = min(lh , rh);
            int len = j - i;
            max_area = max (max_area, len * min_h);
            if(lh > rh)
                j--;
            else
                i++;
        }
        return max_area;
    }
};