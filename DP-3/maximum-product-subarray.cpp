
#include<bits/stdc++.h>
using namespace std;

    int maxProduct(vector<int>& nums) {
        int ans1=INT_MIN,ans2=INT_MIN,cur=1;
        for(int i=0;i<nums.size();i++){
            cur*=nums[i];
            ans1=max(ans1,cur);
            if(cur==0)cur=1;
        }
        // cur=1;
        // for(int i=nums.size()-1;i>=0;i--){
        //     cur*=nums[i];
        //     ans2=max(ans2,cur);
        //     if(cur==0)cur=1;
        // }
        //return max(ans1,ans2);
        return ans1;
    }
int main(){
   
    vector<int> arr={1,2,5,10,50};
    int ans=maxProduct(arr);
    cout<<ans;
    return 0;
}