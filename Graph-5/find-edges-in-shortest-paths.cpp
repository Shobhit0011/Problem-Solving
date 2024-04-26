#include<bits/stdc++.h>
using namespace std;
 
vector<int> dijkitras(int n,vector<vector<pair<int,int>>>& adj,int src)
{
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> distance(n,INT_MAX);
        vector<bool> vis(n, 0);
        distance[src]=0;
        pq.push({0,src});
        while(pq.size())
        {
            auto i=pq.top();
            pq.pop();
            int d=i.first;
            int temp=i.second;
            if( vis[temp]==1)
                continue;
            vis[temp] = 1;
            for(auto i:adj[temp])
            {
                if(distance[i.first]>d+i.second)
                {
                   distance[i.first]=d+i.second;
                   pq.push({distance[i.first],i.first});
                }
            }
        }
        return  distance;
}
    vector<bool> solve(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> src=dijkitras(n,adj,0);
        vector<int> dst=dijkitras(n,adj,n-1);
        int e=edges.size(),shortest=src[n-1];
        vector<bool> ans(e,false);
        for(int i=0;i<e;i++)
        {
            int u=edges[i][0],v=edges[i][1],w=edges[i][2];
            if((src[u]+dst[v]+w==shortest)||(src[v]+dst[u]+w==shortest))
            ans[i]=true;
        }
        return ans;
    }
int main(){

        int n;
        cin>>n;
        vector<vector<int>> edges;
        int k;
        cin>>k;
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>edges[i][j];
            }
        }
        vector<bool> ans=solve(n,edges);
        for(bool i:ans){
            if(i) cout<<"true"<<" ";
            else cout<<"false"<<" ";
        }
        return 0;
            
    }
