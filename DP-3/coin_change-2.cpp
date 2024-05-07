#include<bits/stdc++.h>
using namespace std;

/*
    int solve(vector<int>& coins , int i , int amount , vector<vector<int>>& dp){
        if(dp[i][amount] != -1)return dp[i][amount];
        if(i == 0)return amount%coins[i] == 0;
        int nontake  = solve(coins , i-1  , amount , dp);
        int a = 0;
        if(amount >= coins[i]){
            a = solve(coins , i , amount - coins[i] , dp);
        }
        return dp[i][amount] = a+nontake;
    }
    
*/
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1; 
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                if (dp[i - coin] != INT_MAX) {
                    dp[i] +=  dp[i - coin]  ;
                }
            }
        }
        return dp[amount];
    }



int main(){
   
    vector<int> coins={1,2,5,10,50};
    int amount=109;
    int ans=change(amount,coins);
    cout<<ans;
    return 0;
}