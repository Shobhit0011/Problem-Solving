#include<bits/stdc++.h>
using namespace std;

    int path(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dp) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
        return 0;
    }
    if (grid[i][j] == 2) {
        return 1;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int down = path(grid, i + 1, j, dp);
    int right = path(grid, i, j + 1, dp);
    dp[i][j] = down + right;
    return dp[i][j];
}

    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,1));
        vector<vector<int>> dp(m,vector<int> (n,-1));
        grid[m-1][n-1]=2;
        int ans=0;
       
        return path(grid,0,0,dp);
    }

int main(){

   int m,n;
  cin>>m>>n;
    int ans=uniquePaths(m,n);
    cout<<ans;
    return 0;
}
