#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses);
    for(int i=0;i<prerequisites.size();i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        indegree[prerequisites[i][0]]++;
    }
    queue<int> q;
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int c:adj[x]){
            indegree[c]--;
            if(indegree[c]==0){
                q.push(c);
            }
        }
    }
    for(int i=0;i<numCourses;i++){
        if(indegree[i]!=0) return 0;
    }
    return 1;
}
int main(){
    int n,num;
    cout<<"Enter number of courses:";
    cin>>n;
    cout<<"enter number of prerequisites:";
    cin>>num;
    cout<<"Enter prerequisites:\n";

    vector<vector<int>> prerequisites(num,vector<int>(2));
    for(int i=0;i<num;i++){
        cin>>prerequisites[i][0]>>prerequisites[i][1];
    }
    cout<<"\n";
    if(canFinish(n,prerequisites)){
        cout<<"Possible\n";
    }
    else {
        cout<<"Not Possible!\n";
    }
    return 0;
}
