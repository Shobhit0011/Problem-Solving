#include<bits/stdc++.h>
using namespace std;
class DSU {
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int numNodes){
        parent.resize(numNodes);
        rank.resize(numNodes);
        for(int i=0; i<numNodes; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int node){
        if(node == parent[node]) return node;
        int p = find(parent[node]);
        parent[node] = p;
        return p;
    }

    bool unionNodes(int u, int v){
        int p1 = find(u);
        int p2 = find(v);

        if(p1 == p2) return false;

        if(rank[p1] <= rank[p2]){
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        else{
            parent[p2] = p1;
            rank[p1] += rank[p2];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int numNodes = edges.size();
        DSU dsu(numNodes + 1);
        for(auto& edge: edges){
            bool isPossibleToUnite = dsu.unionNodes(edge[0], edge[1]);
            if(!isPossibleToUnite){
                return edge;
            }
        }

        throw invalid_argument( "all edges are valid");
    }
};
int main(){
   Solution s;
   int n;
   cin>>n;
   vector<vector<int>> edges(n,vector<int>(2));
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    vector<int> ans;
    ans=s.findRedundantConnection(edges);

    return 0;

}
