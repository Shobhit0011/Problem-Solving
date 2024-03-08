#include<bits/stdc++.h>
using namespace std;
    int findMin(vector<int>& nums) {
        int m,s=0;
        int e=nums.size()-1;
        while(s<e){
            m=(s+e)/2;
            if(nums[m]>nums[e])
            s=m+1;
            else
            e=m;
        }
        return nums[(s+e)/2];
    }
    int main(){
        vector<int> nums{4,5,6,7,0,1,2};
       int a=findMin(nums);
       cout<<a;
    }
