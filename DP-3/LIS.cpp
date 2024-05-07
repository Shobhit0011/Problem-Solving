
#include<bits/stdc++.h>
using namespace std;
//    ***DP with binary search***
      
        int BSforlowerbound(vector<int>& LISstorage,int n){
            int l=0,h=LISstorage.size()-1;
            int m,ans=-1;
            while(l<=h){
                m=l+(h-l)/2;
                if(LISstorage[m]>=n){
                    h=m-1;
                }
                else{
                    ans=m;
                    l=m+1;
                }
            }
            return ans+1;
        }

        int lisusingBS(vector<int>& arr){
            vector<int> LISstorage;
            LISstorage.push_back(arr[0]);
            for(int i=1;i<arr.size();i++){
                if(arr[i]>LISstorage.back()){
                    LISstorage.push_back(arr[i]);
                }
                else{
                    int idx=BSforlowerbound(LISstorage,arr[i]);
                    LISstorage[idx]=arr[i];
                }
            }
            return LISstorage.size();
        }

      

      //        *** DP ***

    /* int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n);
        dp[0]=1;
        int ans=dp[0]; 
        int prev;
        for(int i = 1; i < n; i++) {
            prev=0;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    prev=max(dp[j],prev);
                }
            }
            dp[i]=prev+1;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    */

    //         *** RECURSION  *** 

   /* int LIS(vector<int>& nums,int cur,int prev){
         if(cur==nums.size()){
            return 0;
        }
        int take=0;
        if(prev==-1 || nums[prev]<nums[cur]){
            take=1+LIS(nums,cur+1,cur);
        }
        int nontake=LIS(nums,cur+1,prev);
        return max(take,nontake);

    }
   */

    //     ***  MEMOIZATION   ***
/*
  int LIS(vector<int>& nums, int cur, int prev, vector<vector<int>>& memo) {
    if (cur == nums.size()) {
        return 0;
    }
    if (prev != -1 && memo[prev][cur] != -1) {
        return memo[prev][cur];
    }
    int take = 0;
    if (prev == -1 || nums[prev] < nums[cur]) {
        take = 1 + LIS(nums, cur + 1, cur, memo);
    }
    int nontake = LIS(nums, cur + 1, prev, memo);
    if (prev != -1) {
        memo[prev][cur] = max(take, nontake);
        return memo[prev][cur];
    } else {
        return max(take, nontake);
    }
}
*/
int lengthOfLIS(vector<int>& nums) {
    return lisusingBS(nums);
}
int main(){
    vector<int> arr={1,2,5,0,21,43,11,54,67};
    int ans=lengthOfLIS(arr);
    cout<<ans;
    return 0;
}