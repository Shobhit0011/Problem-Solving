#include<bits/stdc++.h>
using namespace std;
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            src--;
            dst--;
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            pq.push({0,src});
            vector<vector<int>> adj(n);
            vector<vector<int>> rev(n);
            for(auto it:edges)
            {
                adj[it[0]-1].push_back(it[1]-1);
                rev[it[1]-1].push_back(it[0]-1);
            }
            set<pair<int,int>> vis;
            vis.insert({src,1});
            vis.insert({src,2});
            while(pq.size())
            {
                auto it=pq.top();
                pq.pop();
                int node=it.second;
                int cost=it.first;
                if(node==dst)
                return cost;
                for(auto it:adj[node])
                {
                    if(vis.find({it,1})==vis.end())
                    {
                        vis.insert({it,1});
                        pq.push({cost,it});
                    }
                }
                for(auto it:rev[node])
                {
                    if(vis.find({it,2})==vis.end())
                    {
                        vis.insert({it,2});
                        pq.push({cost+1,it});
                    }
                }
            }
            return -1;
        }
int main(){
        int source,destination,n,m;
        cout<<"enter no of nodes\n";
        cin>>n;
        cout<<"Enter No of edges:\n";
        cin>>m;
        vector<vector<int>> adj(n,vector<int>(2));
        cout<<"enter the edges:\n";
        for(int i=0;i<m;i++){
            cin>>adj[i][0]>>adj[i][1];
        }
        cout<<"enter src and dest\n";
        cin>>source>>destination;
        cout<<"answer: ";
        int ans=minimumEdgeReversal(adj,n,source,destination);
        cout<<ans<<"\n";

        return 0;
    }
//N=3
// M=2
// edges[][]={{1,2},{3,2}}
// src=1
// dst=3