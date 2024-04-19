#include<bits/stdc++.h>
using namespace std;

 bool check(int i,int j,int n,int m)
    {
        return i>=0&&j>=0&&i<n&&j<m;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        int news=0,l=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    vis[i][j]=1;
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                    news++;
            }
        }
        if(news==0)return 0;
        int cur=0;
        vector<pair<int,int>> arr;
        arr.push_back({0,1});arr.push_back({1,0});arr.push_back({0,-1});arr.push_back({-1,0});
        while(q.size())
        {
            int s=q.size();
            while(s--)
            {
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                for(auto d:arr)
                {
                    if(check(x+d.first,y+d.second,n,m)&&vis[x+d.first][y+d.second]==-1&&grid[x+d.first][y+d.second]==1)
                    {
                        grid[x+d.first][y+d.second]=2;
                        cur++;
                        vis[x+d.first][y+d.second]=1;
                        q.push({x+d.first,y+d.second});
                    }
                }
            }
            l++;
        }
        if(cur==news)return l-1;
        return -1;
    }
int main(){
        vector<vector<int>> vec;
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                cin>>vec[i][j];
            }
        }
        bool ans=orangesRotting(vec);
        return 0;
} 
