#include<bits/stdc++.h>
using namespace std;
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums[0]!=nums[1])return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2])return nums[nums.size()-1];
        int l=0,h=nums.size()-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(nums[m]!=nums[m-1] && nums[m]!=nums[m+1])return nums[m];
            else if(nums[m]==nums[m+1]){
                if(m%2==0){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
            else{
                 if(m%2==0){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }
        }
        return -1;
    }
    int main(){
        vector<int> a{1,1,2,2,3,3,4,4,5,6,6,7,7,8,8,9,9,10,10};
        int ans=singleNonDuplicate(a);
        cout<<"Answer :"<<ans;
    }
