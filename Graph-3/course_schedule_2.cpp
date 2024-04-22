#include<bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>> adj(numCourses);
        vector<int> in(numCourses);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            in[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<in.size();i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int x=q.front();
            ans.push_back(x);
            q.pop();
            for(int i:adj[x]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        for(int i:in){
            if(i!=0){
                return {};
            }
        }
        return ans;
    }
int main(){
    int n,num;
    cout<<"Enter number of courses:";
    cin>>n;

    //4
    
    cout<<"enter number of prerequisites:";
    cin>>num;

    //4

    cout<<"Enter prerequisites:\n";

    //[1,0],[2,0],[3,1],[3,2]]

    vector<vector<int>> prerequisites(num,vector<int>(2));
    for(int i=0;i<num;i++){
        cin>>prerequisites[i][0]>>prerequisites[i][1];
    }
    vector<int> ans;
    ans=findOrder(n,prerequisites);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"->";
    }
    return 0;
   
}
