#include<bits/stdc++.h>
using namespace std;
bool possibletomakemid(vector<int> &freqarr,int mid,int max){
    int totalitem=0;
    int curfooditm;
    for(int freq:freqarr){
        curfooditm=freq/mid;
        totalitem+=curfooditm;
    }
    return totalitem>=max;
}
int maximumlunch(vector<int> &fooditem,int max){
    int n=*max_element(fooditem.begin(),fooditem.end())+1;
    vector<int> freqarr(n,0);
    int ans;
    for(int item:fooditem){
        freqarr[item]++;
    }
    int low=0,high=*max_element(freqarr.begin(),freqarr.end());
    while(low<=high){
        int mid=(low+high)/2;
        if(possibletomakemid(freqarr,mid,max)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return ans;
}
int main(){
    vector<int> fooditem={1,3,1,3,10,3,6,6,13};
    int maxitem=4;
    int ans=maximumlunch(fooditem,maxitem);
    cout<<"Number of lunchboxes:  "<<ans;
    return 0;
}