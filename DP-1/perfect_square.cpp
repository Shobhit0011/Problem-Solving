#include<bits/stdc++.h>
using namespace std;

int sol(vector<int>& dp,int n){
    if(n == 0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int ans=n;
    for(int i=1;i*i<=n;i++){
        int t=i*i;
       ans=min(ans,1+sol(dp,n-t));
    }
    dp[n]=ans;
    return dp[n];
}
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return sol(dp,n);
    }

int main(){
    int n;
    cin>>n;
    int minsquares=numSquares(n);
    cout<<minsquares;
    return 0;
}