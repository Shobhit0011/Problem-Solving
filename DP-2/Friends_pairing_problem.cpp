#include<bits/stdc++.h>
using namespace std;
    
    // DP
    int solveDP(int n) 
    { 
        vector<int> dp(n+1,0);
        dp[0]=1;  
        dp[1]=1;  
        
        for(int i=2;i<=n;i++)
        {
            dp[i]=1*dp[i-1] + (i-1)*dp[i-2];
        }
        return dp[n];
    }

    //  Memoisation
    int SolveCache(int n, vector < int > & dp) {
        if (n <= 2) return n;
        if (dp[n] != -1) return dp[n];
        return dp[n] = SolveCache(n - 1, dp) + (n - 1) * SolveCache(n - 2, dp);
    }
    


     // Recursion
    /*
    int solveRecursion(int n) 
    { 
        if(n<=2) return n;
        return solveRecursion(n-1)+ (n-1)*solveRecursion(n-2);
    }
    */


    int countFriendsPairings(int n){
        return solveDP(n);
    }
int main(){
    int n;
    cin>>n;
    int ans=countFriendsPairings(n);
    cout<<ans;
    return 0;
}