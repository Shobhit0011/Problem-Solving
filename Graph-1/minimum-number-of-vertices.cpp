#include<bits/stdc++.h>
using namespace std;

 void dfs(int n,vector<int>& vis,vector<vector<int>>& adj)
    {
        if(vis[n]==1)
            return;
        vis[n]=1;
        for(auto it:adj[n])
        dfs(it,vis,adj);
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        vector<pair<int,int>> q;
        for(int i=0;i<n;i++)
        q.push_back({ind[i],i});
        sort(q.begin(),q.end());
        vector<int> ans;
        vector<int> vis(n,-1);
        for(auto it:q)
        {
            int n=it.second;
            if(vis[n]==-1)
            {
                ans.push_back(n);
                dfs(n,vis,adj);
            }
        }
        return ans;
    }
     int main(){
    int n;
   
    cout<<"Enter the no of Node: ";
    cin>>n;
       vector<vector<int>> vec(n,vector<int>(2));
       cout<<"Enter the value of Node:\n";
       for(int i=0;i<n;i++){
        for(int j=1;j<2;j++){
        cin>>vec[i][j];
        }
       }
        vector<int> ans=findSmallestSetOfVertices(n,vec);
       cout<<"Minimun nodes are: ";
       for(int i=0;i<ans.size();i++){
        cout<<ans[i];
       }
        return 0;
    }