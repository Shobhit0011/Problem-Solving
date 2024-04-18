#include<bits/stdc++.h>
using namespace std;

int height(int root,vector<vector<int>>& arr,int& ans){
    int mx=0;
    for(auto it:arr[root]){
        int t=height(it,arr,ans);
        ans=max(ans,mx+t);
        mx=max(mx,t);
    }
    return mx+1;
}
int solve(vector<int> &A) {
   vector<vector<int>> arr(A.size(),vector<int> (0));
   int root=-1;
   for(int i=0;i<A.size();i++){
       if(A[i]==-1){
           root=i;
           continue;
       }
       else{
           arr[A[i]].push_back(i);
           
       }
   }
   int ans=0;
   height(root,arr,ans);
   return ans;
   
}

 int main(){
    int n;
   
    cout<<"Enter the no of Node: ";
    cin>>n;
       vector<int> vec(n);
       cout<<"Enter the value of Node:\n";
       for(int i=0;i<n;i++){
        cin>>vec[i];
       }
        int ans=solve(vec);
       cout<<"The Largest Path is  "<<ans;
        return 0;
    }
