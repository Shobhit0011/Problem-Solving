#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool>& vis, stack<int>& st, int v) {
    vis[v] = true;
    for (int i : adj[v]) {
        if (!vis[i]) {
            dfs(adj, vis, st, i);
        }
    }
    st.push(v);
}
void dfsforSCC(vector<vector<int>>& adj, vector<bool>& vis, int v) {
    vis[v] = true;
    for (int i : adj[v]) {
        if (!vis[i]) {
            dfsforSCC(adj, vis, i);
        }
    }
}
int kosaraju(int V, vector<vector<int>>& adj) {
    vector<vector<int>> revadj(V);

    for (int i = 0; i < V; ++i) {
        for (int j : adj[i]) {
                revadj[j].push_back(i);
        }
    }

    vector<bool> vis(V, false);
    stack<int> st;

    for (int i = 0; i < V; ++i) {
        if (!vis[i]) {
            dfs(adj, vis, st, i);
        }
    }

    int c = 0;
    vis.assign(V, false);

    while (!st.empty()) {
        int v = st.top();
        st.pop();
        if (!vis[v]) {
            dfsforSCC(revadj, vis, v);
            c++;
        }
    }

    return c;
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
    }
    int ans=kosaraju(n,adj);
    cout<<"answer:"<<ans;
    return 0;
}