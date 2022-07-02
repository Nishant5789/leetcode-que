class Solution {
    
    void mergesort(vector<int> &nums,int s, int e)
    {
        if(s>=e)
        {
            return;
        }
        int mid=(s+e)/2;
        
        mergesort(nums, s, mid);
        
        mergesort(nums, mid+1, e);
        
        merge(nums, s, e);

    }
    
    void merge(vector<int> &nums,int s,int  e)
    {
        int mid=(s+e)/2;
        
        int l1=mid-s+1;
        int l2=e-mid;
        int k=s;
        
        int* first = new int[l1];
        int* second = new int[l2];
        for(int i=0; i<l1; i++)
        {
            first[i]=nums[k++];
        }
        k=mid+1;
        for(int i=0; i<l2; i++)
        {
            second[i]=nums[k++];
        }
        
        int i=0;
        int j=0;
        int mainindex=s;
        
        while(i<l1 && j<l2)
        {
            if(first[i]>second[j])
            {
                nums[mainindex++]=second[j++];
            }
            else
            {
                nums[mainindex++]=first[i++];
            }
        }
        
        while(i<l1)
        {
            nums[mainindex++]=first[i++];
        }
        while(j<l2)
        {
            nums[mainindex++]=second[j++];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int s=0, e=nums.size()-1;
        mergesort(nums, s, e);
        return nums;
        
        
    }
};