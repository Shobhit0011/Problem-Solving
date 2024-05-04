#include<bits/stdc++.h>
using namespace std;

    int minimumEffortPath(vector<vector<int>>& grid) {
        priority_queue < pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > pq;
  
        pq.push({0, {0,0}});
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int> (m,INT_MAX));
        int dy[]={-1,0,1,0};
        int dx[]={0,1,0,-1};
        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == m-1) return dis;
            for(int i=0;i<4;i++){
                int row = row+dy[i];
                int col = col+dx[i];
                if(row>=0 && col>=0 &&col<m && row<n){
                    int x = max(dis , abs(grid[row][col]-grid[row][col]) );
                    if(x<dist[row][col]){
                         dist[row][col]=x;
                        pq.push({x,{row,col}});
                    }
                }

            }

        }
        return 0;
    }
int main(){
        int n,c;
        cin>>n>>c;
        vector<vector<int>> heights;
        int k;
        cin>>k;
        for(int i=0;i<n;i++){
            for(int j=0;j<c;j++){
                cin>>heights[i][j];
            }
        }
        int ans=minimumEffortPath(heights);
       cout<<ans;
        return 0;
            
    }