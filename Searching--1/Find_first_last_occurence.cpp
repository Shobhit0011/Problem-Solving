#include<bits/stdc++.h>
using namespace std;
    vector<int> searchRange(vector<int>& nums, int target) {
        int i,j;
        vector<int> arr{-1,-1};
         int n=nums.size();
        int s=0,m;
        int e=n-1;
        if(n==0)
            return arr;
            else{
        while(s<=e){
           m=(s+e)/2;
           if(nums[m]==target){
              arr[0]=m;
               e=m-1;
           }
           else if(target>nums[m])
              s=m+1;
           else
           e=m-1;
        }
        s=0;
        e=n-1;
         while(s<=e){
           m=(s+e)/2;
           if(nums[m]==target){
              arr[1]=m;
               s=m+1;
           }
           else if(target>nums[m])
              s=m+1;
           else
           e=m-1;
        }}
        return arr;
    }
    int main(){
        vector<int> nums{5,7,7,8,8,10};
        int target=8;
        vector<int> ans(2,-1);
        ans=searchRange(nums,target);
        cout<<"("<<ans[0]<<","<<ans[1]<<")";
        return 0;
    }

