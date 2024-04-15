#include<bits/stdc++.h>
using namespace std;

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
         unordered_map<int,vector<int>> mp;
         for(auto x:edges){
              mp[x[0]].push_back(x[1]);
              mp[x[1]].push_back(x[0]);
         }
         vector<bool> visited(n,0);
         queue<int> q;
         q.push(source);
         visited[source]=1;
         while(!q.empty()){
            int x=q.front();
            q.pop();
            vector<int> v=mp[x];
            for(int i=0;i<v.size();i++){
                 if(visited[v[i]]==false){
                    visited[v[i]]=1;
                    q.push(v[i]);
                 }
            }
         }
         return visited[destination];
    } 
    int main(){
        int source,destination,n;
        cout<<"Enter No of edges:\n";
        cin>>n;
        vector<vector<int>> edges(n,vector<int>(2));
        cout<<"enter the edges:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<2;j++){
                cin>>edges[i][j];
            }
        }
        cout<<"Enter sources ans Destination:  ";
        cin>>source>>destination;
        bool ans=validPath(n,edges,source,destination);
        if(ans){
            cout<<"POSSIBLE !!!!";
        }
        else{
            cout<<"NOT Possible";
        }
        return 0;
    }
