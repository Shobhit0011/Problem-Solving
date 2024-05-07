#include<bits/stdc++.h>
using namespace std;
  /*   ******  DP  *******    */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        dp[n-1][m-1]=(dungeon[n-1][m-1]<=0?(-dungeon[n-1][m-1]+1):1);
        
        for (int j = m-2; j >= 0; --j) {
            dp[n-1][j] = max(1, dp[n-1][j+1] - dungeon[n-1][j]);
        }
        
        for (int i = n-2; i >= 0; --i) {
            dp[i][m-1] = max(1, dp[i+1][m-1] - dungeon[i][m-1]);
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                     if(dungeon[i][j]<=0){
                        if(i+1<n && j+1<m){
                            dp[i][j]=abs(dungeon[i][j])+min(dp[i+1][j],dp[i][j+1]);
                        }
                     }
                     else{
                        if(i+1<n && j+1<m){
                            dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
                        }
                     }
            }
        }
        return dp[0][0];
    }

int main(){
    vector<vector<int>> dungeon={{1,2,3},{-1,8,-22},{4,3,5}};
    int ans=calculateMinimumHP(dungeon);
    cout<<ans;
    return 0;
}
