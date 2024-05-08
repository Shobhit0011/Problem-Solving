#include<bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp(n,1);
    vector<int> cnt(n,1);
    int maxi=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
                cnt[i]=cnt[j];
            }
            else if(nums[i]>nums[j] && dp[j]+1==dp[i]){
                cnt[i]+=cnt[j];
            }
        }
        maxi=max(maxi,dp[i]);
    }
    int nos=0;
    for(int i=0;i<n;i++){
        if(dp[i]==maxi) nos+=cnt[i];
    }
    return nos;
}

int main(){
    vector<int> arr={1,3,5,4,7};
    int nos=findNumberOfLIS(arr);
    cout<<nos;
    return 0;
}