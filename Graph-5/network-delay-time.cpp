
#include<bits/stdc++.h>
using namespace std;
 
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:times){
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        }
        vector<bool> vis(n,0);
        vector<int> distance(n,INT_MAX);
        distance[k-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k-1});
        while(pq.size())
        {
            int temp=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            if(vis[temp]==1)continue;
            vis[temp]=1;
            for(auto it:adj[temp])
            {
                if(distance[it.first]>distance[temp]+it.second)
                {
                    distance[it.first]=distance[temp]+it.second;
                    pq.push({distance[it.first],it.first});
                }
            }
        }
        for(auto it:distance)
        if(it==INT_MAX)return-1;
        int ans=INT_MIN;
        for(auto it:distance)
        ans=max(ans,it);
        return ans;
    }
     int main(){

        int n;
        cin>>n;
        vector<vector<int>> times;
        int k;
        cin>>k;
        for(int i=0;i<(n * (n - 1) / 2);i++){
            for(int j=0;j<3;j++){
                cin>>times[i][j];
            }
        }
        int ans=networkDelayTime(times,n,k);
        cout<<ans;
        return 0;
            
    }
