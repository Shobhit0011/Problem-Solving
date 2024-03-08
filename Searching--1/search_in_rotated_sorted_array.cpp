#include<bits/stdc++.h>
using namespace std;
    bool search(vector<int>& nums, int t) { 
        int ans=0,l=0,r=nums.size()-1,mid=0;
        int n=nums.size()-1;
    
    
        while(l<=r){
            mid=(l+r)/2;
            if(t==nums[mid]){return true;}
            if(nums[l]==nums[mid]&&nums[r]==nums[mid]){
                l++;r--;
            }else if(nums[mid]>nums[r]){
                 if(t>nums[mid]||t<nums[0]){
                     l=mid+1;
                 }else{
                     r=mid-1;
                 }
             }else{
                 if(t<nums[mid]||t>nums[r]){
                     r=mid-1;
                 }else{
                     l=mid+1;
                 }
             }
        }
        
        return false;
    }
    int main(){
        vector<int> nums{8,9,10,1,2,3,4,5,6,7};
        int target=8;
        bool ans;
        ans=search(nums,target);
        if(ans){
            cout<<"Element Found";

        }
        else{
            cout<<"Not Found";
        }
        return 0;
    }
