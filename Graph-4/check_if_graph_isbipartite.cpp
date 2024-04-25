#include<bits/stdc++.h>
using namespace std;

    bool isComponentbipartite(int src,vector<int>& color,vector<vector<int>>& adj,queue<int>& q){
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int neigh:adj[x]){
                if(color[neigh]==-1){
                    color[neigh]=1^color[x];
                    q.push(neigh);
                }
                else if(color[neigh]!=1^color[x]){
                        return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> color(v,-1);
        queue<int> q;
        for(int i=0;i<v;i++){
            if(color[i]!=-1) continue;
            if(!isComponentbipartite(i,color,graph,q)){
                return false;
            }
        }
        return true;
    }
int main(){
    int n,e;
    cout<<"enter no of vertices and edges:\n";
    cin>>n>>e;
    vector<vector<int>> edges(e,vector<int>(2));
    vector<vector<int>> adj(n);
    cout<<"enter edges:\n";
    for(int i=0;i<e;i++){
        cin>>edges[i][0]>>edges[i][1];
    }
    for(int i=0;i<n;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    if(!isBipartite(adj)) {
       cout<<"Yess!!graph is bipartite\n";
       }
    else 
      cout<<"NO!!Graph is bipartite\n";
    return 0;
}