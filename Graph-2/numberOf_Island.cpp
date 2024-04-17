#include<bits/stdc++.h>
using namespace std;

    void solve(vector<vector<char>>& grid,vector<vector<bool>>& visited,int i,int j){
        if(i<0 || j<0 ||i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || vis[i][j]){
            return;
        }
        vis[i][j]=1;
        solve(grid,visited,i-1,j);
        solve(grid,visited,i,j+1);
        solve(grid,visited,i+1,j);
        solve(grid,visited,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int c=0;
        
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                        solve(grid,visited,i,j);
                        c++;
                }
            }
        }
        return c;
    }
    int main(){
       
           vector<vector<char>> grid={{'1','1','1','1','0'},
                                    {'1','1','0','1','0'},
                                    {'1','1','0','0','0'},
                                    {'0','0','0','0','0'} };
         
        int ans=numIslands(grid);
        cout<< ans;
        return 0;
    }
