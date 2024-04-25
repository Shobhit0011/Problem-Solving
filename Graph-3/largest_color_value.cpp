#include<bits/stdc++.h>
using namespace std;
    int largestPathValue(string color, vector<vector<int>>& adj) {
        int n=color.size();
        vector<int> indeg(n,0);
        vector<vector<int>> adj(n);
        for(auto it:adj)
        {
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        queue<int> q;
        vector<int> vis(n,-1);
        vector<vector<int>> c(n,vector<int>(26,0));
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                c[i][color[i]-'a']++;
                q.push(i);
                vis[i]=1;
            }
        }
        int ans=0;
        while(q.size())
        {
            int t=q.front();
            q.pop();
            int mx=0;
            for(auto it:c[t])
            mx=max(mx,it);
            ans=max(ans,mx);
            for(auto it:adj[t])
            {
                for(int i=0;i<26;i++)
                    c[it][i]=max(c[it][i],c[t][i]+(color[it]-'a'==i));
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        for(auto it:vis)
            if(it==-1)return -1;
        return ans;
    }
int main(){
        string st;
        cout<<"Enter string:\n";
        cin>>st;
         int ne,sn;
        cout<<"enter the adj and node:\n";
        vector<vector<int>> adj(sn,vector<int>(2));
        
       
        cin>>ne;
        for(int i=0;i<ne;i++){
            for(int j=0;j<2;j++){
                cin>>adj[i][j];
            }
        }
        cout<<"OUTPUT:"<<endl;
        //[[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
        int ans=largestPathValue(st,adj);
        cout<<ans;

        return 0;
    }
