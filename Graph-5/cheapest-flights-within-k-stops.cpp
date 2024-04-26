
#include<bits/stdc++.h>
using namespace std;
 int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:flights)
        adj[it[0]].push_back({it[1],it[2]});
        pq.push({0,0,src});
        k++;
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        while(pq.size())
        {
            int t=pq.top()[0];
            int dis=pq.top()[1];
            int node=pq.top()[2];
            pq.pop();
            if(t>=k)continue;
            for(auto it:adj[node])
            {
                if(dist[it.first]>dis+it.second)
                {
                    dist[it.first]=dis+it.second;
                    pq.push({t+1,dist[it.first],it.first});
                }
            }
        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
    int main(){

        int n;
        cin>>n;
        vector<vector<int>> flight;
        int src,dst;
        cin>>src>>dst;
        int k;
        cin>>k;
        for(int i=0;i<(n * (n - 1) / 2);i++){
            for(int j=0;j<3;j++){
                cin>>flight[i][j];
            }
        }
        int ans=findCheapestPrice(n,flight,src,dst,k);
        cout<<ans;
        return 0;
            
    }
    