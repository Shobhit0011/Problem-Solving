#include<bits/stdc++.h>
using namespace std;

    int findmax(vector<int>& nums,int i,vector<int>& cache){
        if(i<0)return 0;
        if(cache[i]!=-1){
            return cache[i];
        }
        cache[i]=max((nums[i]+findmax(nums,i-2,cache)),findmax(nums,i-1,cache));
        return cache[i];
    }
    int rob(vector<int>& nums) {
        vector<int> cache(nums.size()+1,-1);
        return findmax(nums,nums.size()-1,cache);
    }

int main(){
    int n;
    cin>>n;
    vector<int> houses(n);
    for(int i=0;i<n;i++){
        cin>>houses[i];
    }
    int maxamountcanrob=rob(houses);
    cout<<maxamountcanrob;
    return 0;
}