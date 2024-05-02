#include<bits/stdc++.h>
using namespace std;

     int solvememo(vector<int>& nums,int i,int l,vector<int>& cache){
        if(i>l)return 0;
        if(cache[i]!=-1){
            return cache[i];
        }
        cache[i]=max((nums[i]+solvememo(nums,i+2,l,cache)),solvememo(nums,i+1,l,cache));
        return cache[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> cache(nums.size()+1,-1);
        vector<int> cache1(nums.size()+1,-1);

       return max(solvememo(nums,1,nums.size()-1,cache),solvememo(nums,0,nums.size()-2,cache1));
    }
int main(){
    vector<int> nums={1,2,3,1};
    int answer=rob(nums);
    cout<<answer;
    return 0;
}