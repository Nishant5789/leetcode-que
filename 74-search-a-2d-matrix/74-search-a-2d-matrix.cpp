class Solution {
    bool binary_search(vector<int> &arr, int target)
    {
        int mid=0, left=0, right=arr.size()-1;
        while(left<=right)
        {
            mid=left +(right-left)/2;
            if(arr[mid]==target)
                return 1;
            else
                if(arr[mid]>target)
                    right= mid-1;
            else
                left= mid+1;
        }
        return 0;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(), c=matrix[0].size();
        for(int i=0; i<r; i++)
        {
            if(matrix[i][0]<=target && target<=matrix[i][c-1])
            {
                if(binary_search(matrix[i], target))
                {
                    return 1;
                }
            }
        }
        return 0;
        
    }
};