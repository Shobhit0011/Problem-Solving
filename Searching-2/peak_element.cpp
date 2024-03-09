#include<bits/stdc++.h>
using namespace std;
int bs(vector <int> a,int l,int h,int n){
    if(n==1)return a[0];
    if(a[0]>a[1])return a[0];
    if(a[h]>a[h-1])return a[h];
    if(l>h){
        return -1;
    }
    int m=l+(h-l)/2;
    if(a[m]>a[m-1] && a[m]>a[m+1])
    {
        return a[m];
    }
    else if(a[m]<a[m+1]){
          return bs(a,m+1,h,n);
    }
    else if(a[m-1]>a[m]){
        return bs(a,l,m-1,n);
    
    }
    else{
        return bs(a,m-1,h,n);
    }
}
int main(){
    vector<int > a{0,5,4,3,2,1,2,3,4};
    int n=9;
    int ans=bs(a,0,n-1,n);
    cout<<"answer= "<<ans;
    return 0;
}