#include<bits/stdc++.h>
using namespace std;
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& s, int start, int end) 
    {
        vector<vector<pair<double,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            auto t=edges[i];
            adj[t[0]].push_back({t[1],s[i]});
            adj[t[1]].push_back({t[0],s[i]});
        }
        vector<double>distance(n,INT_MIN);
        vector<bool> visited(n, 0);
        distance[start]=1.0;
        priority_queue<pair<double,double>> pq;
        pq.push({1.0,start});
        while(pq.size())
        {
            auto t=pq.top();
            pq.pop();
            double temp=t.second;
            double d=t.first;
            if( visited[temp]==1){
                continue;
            }
            visited[temp] = 1;
            for(auto i:adj[temp])
            {
                if(distance[i.first]<=distance[temp]*i.second)
                {
                    distance[i.first]=distance[temp]*i.second;
                    pq.push({distance[i.first],i.first});
                }
            }
        }
        if(distance[end]==INT_MIN)return 0;
        return distance[end];
    }
     int main(){

        int n;
        cin>>n;
        vector<vector<int>> edges;
        vector<double> s;
        int start,end;
        cin>>start>>end;
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>edges[i][j];
            }
        }
        double ans=maxProbability(n,edges,s,start,end);
        cout<<ans;
        return 0;
            
    }
