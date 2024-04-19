#include<bits/stdc++.h>
using namespace std;

 bool is_valid(int x,int y,vector<vector<int> > &grid)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            return 0;
        return 1;
    }
    void dfs(int x,int y,vector<vector<bool> > &visited,vector<vector<int> > &grid){
        if(visited[x][y])
            return;
        visited[x][y] = 1;
        int up,down,left,right;
        up=down=left=right=0;
        if(grid[x][y] == 1)
            left=right=1;
        else if(grid[x][y] == 2)
            up=down=1;
        else if(grid[x][y] == 3)
            left=down=1;
        else if(grid[x][y] == 4)
            down=right=1;
        else if(grid[x][y] == 5)
            up = left = 1;
        else
            right=up=1;
        if(up)
        {
            int curx=x-1,cury=y;
            if(is_valid(curx,cury,grid) && (grid[curx][cury]==2 || grid[curx][cury]==3 || grid[curx][cury]==4))
               dfs(curx,cury,visited,grid);
        }
        if(down)
        {
            int curx=x+1,cury=y;
            if(is_valid(curx,cury,grid) && (grid[curx][cury]==2 || grid[curx][cury]==5 || grid[curx][cury]==6))
               dfs(curx,cury,visited,grid);
        }
        if(left)
       {
            int curx=x,cury=y-1;
            if(is_valid(curx,cury,grid) && (grid[curx][cury]==1 || grid[curx][cury]==4 || grid[curx][cury]==6))
               dfs(curx,cury,visited,grid);
       }
        if(right)
       {
            int curx=x,cury=y+1;
            if(is_valid(curx,cury,grid) && (grid[curx][cury]==1 || grid[curx][cury]==3 || grid[curx][cury]==5))
                dfs(curx,cury,visited,grid);
       }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        if(!n)
            return 1;
        int m = grid[0].size();
        vector <vector<bool> > visited(n,vector<bool>(m,0));
        dfs(0,0,visited,grid);
        return visited[n-1][m-1];
    }
int main(){
        vector<vector<int>> vec;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                cin>>vec[i][j];
            }
        }
        bool ans=hasValidPath(vec);
        return 0;
    } 