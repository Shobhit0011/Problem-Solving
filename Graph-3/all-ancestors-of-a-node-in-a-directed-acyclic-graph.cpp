#include<bits/stdc++.h>
using namespace std;
 vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> in(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            in[edges[i][1]]++;
        }
        queue<int> q;
        for(int i=0;i<in.size();i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<vector<int>> ans(n);
        while(!q.empty()){
            int x=q.front();
             q.pop();
             for(int c:adj[x]){
                ans[c].push_back(x);
                vector<int> op=ans[x];
                while(!op.empty()){
                    if(find(ans[c].begin(),ans[c].end(),op.back())==ans[c].end())
                        ans[c].push_back(op.back());
                    op.pop_back();
                }
                in[c]--;
                if(in[c]==0){
                    q.push(c);
                }
             }
        }
        for(int i=0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
  int main(){
        int sn,ne;
        cout<<"Enter No of nodes:\n";
        cin>>sn;
        vector<vector<int>> adj(sn,vector<int>(2));
        cout<<"enter the edges:\n";
        cin>>ne;
        for(int i=0;i<ne;i++){
            for(int j=0;j<2;j++){
                cin>>adj[i][j];
            }
        }
        cout<<"OUTPUT:"<<endl;
        //[[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
        vector<vector<int>>ans=getAncestors(sn,adj);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                  cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }

        return 0;
    }