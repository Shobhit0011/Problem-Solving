#include<bits/stdc++.h>
using namespace std;

 
    void dfs(unordered_map<int,vector<int>>& mp,int s,vector<bool>& visited){
        visited[s]=true;
        
        for(int i:mp[s]){
            if(!visited[i]){
                dfs(mp,i,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(isConnected.size()+1,false); 
        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    mp[i+1].push_back(j+1);
                }
            }
        }
        int cnt=0;
        for(auto i:mp){
            if(!visited[i.first]){
                dfs(mp,i.first,visited);
                cnt++;
            }
        }
        return cnt;
    }
  int main(){
        int source,destination,n;
        cout<<"Enter No of vertices:\n";
        cin>>n;
        vector<vector<int>> edges(n,vector<int>(n));
        cout<<"enter the edges:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>edges[i][j];
            }
        }
        int a=findCircleNum(edges);
        cout<<"Number of connected components:";
        cout<<a;
        return 0;
    }
