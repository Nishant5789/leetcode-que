#include<bits/stdc++.h>
using namespace std;
class Solution {
    
    int find_pivot(vector<int>& nums,int left,int right)
    {
        // if array is laready sorted
        if(nums[left] < nums[right])
            return 0;
        
        int mid;
        //Iterative binary search
        while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]<nums[0])
                right = mid;
            else
                left = mid+1;
        }
        return mid;
    }
    
    int binary_search(vector<int>& nums,int left,int right,int target)
    {
        int mid;
        //Iterative binary search
        while(left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        // if size of arra y is zero 
        if(n==0)
            return -1;
        else 
            // if array only exits one elemnet
            if(n==1)
            return nums[0]==target?0:-1;
        
        int pivot = find_pivot(nums,0,n-1);
        // here pivot return bigeer number exits in array
        cout << nums[pivot] << " ";
        // if pivot number is same as target
        // why 
        // because if arry is already sorted and target is fisrt element so we need to chage the below line codition for first element 
        if(nums[pivot]==target)
            return pivot;
        
        return target>nums[n-1]?binary_search(nums,0,pivot,target):binary_search(nums,pivot+1,n-1,target);
    }
};