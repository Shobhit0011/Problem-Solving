#include<bits/stdc++.h>
using namespace std;
int NthRoot(int n, int m){ 
	     if(m==1)return 1;
	    long long l=1,h=m;
	    while(l<=h){
	        long long mid=l+(h-l)/2;
	        long long a=1;int b=n;
	        while(b>0){
	            a*=mid;
	            if(a>m)break;
	            b--;
	        }
	        if(a==m)return mid;
	        else if(a<m){
	            l=mid+1;
	        }
	        else{
	            h=mid-1;
	        }
	    }
	    return -1;
	}  
	 int main(){
		int n,m;
		cout<<"Enter the values of n and m:\n";
        cin>>n>>m;
		int ans=NthRoot(n,m);
		cout<<"Answer is:"<<ans;
		return 0;
	}