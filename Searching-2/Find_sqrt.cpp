#include<bits/stdc++.h>
using namespace std;
int main(){
        int x;
		cout<<"Enter the value:  ";
		cin>>x;
        if(x==0 || x==1)return x;
        int s=1,e=x,m=-1;
        while(s<=e){
            m=s+(e-s)/2;
            if(m*m==x)return m;
            else if((long)m*m>(long)x){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        cout<<"Ans: "<<e;
		return 0;
    }
