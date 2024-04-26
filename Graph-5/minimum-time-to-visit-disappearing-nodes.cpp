
#include<bits/stdc++.h>
using namespace std;
 
vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distance(n,INT_MAX);
        vector<bool> visited(n, 0);
        distance[0]=0;
        pq.push({0,0});
        while(pq.size())
        {
            auto t=pq.top();
            pq.pop();
            int d=t.first;
            int temp=t.second;
            if( visited[temp]==1){
                continue;
            }
            visited[temp] = 1;
            for(auto i:adj[temp])
            {
                if(disappear[i.first]>d+i.second&&distance[i.first]>distance[temp]+i.second)
                {
                   distance[i.first]=distance[temp]+i.second;
                   pq.push({distance[i.first],i.first});
                }
            }
        }
        for(int i=0;i<n;i++){
        if(distance[i]>=INT_MAX){
            distance[i]=-1;
        }
        }
        return distance;
    }
    int main(){

        int n;
        cin>>n;
        vector<vector<int>> edges;
        vector<int> disappear;
        for(int i=0;i<n;i++){
            cin>>disappear[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>edges[i][j];
            }
        }
        vector<int> ans=minimumTime(n,edges,disappear);
        for(int i:ans){
            cout<<i;
        }
        return 0;
            
    }