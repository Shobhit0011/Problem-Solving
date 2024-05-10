#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int mod=1e9+7;
int solve(int k, int n, int target,  vector<vector<int>>&dp){
   if(target==0 and n==0)
   return 1;
   if(n==0 or target<=0)
   return 0;
   int ans=0;
   if( dp[n][target]!=-1)
   return dp[n][target];
   for(int i=1;i<=k;i++)
       ans=(ans+ solve(k, n-1, target-i, dp))%mod;
   return dp[n][target]=ans%mod;
}
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(k, n, target, dp);
    }
};
int main(){
    Solution sol;
    int n,k,target;
    cin>>n>>k>>target;;
    int numofrolls=sol.numRollsToTarget(n,k,target);
    cout<<numofrolls;
    return 0;
}