#include<bits/stdc++.h>
using namespace std;

    int jump(vector<int>& nums) {
        int ans = 0;
        int cur = 0;
        int idx = 0; 
        
        for (int i = 0; i < nums.size() - 1; i++) {
            idx = max(idx, i + nums[i]);
            if (i == cur) {
                ans++;
                cur = idx;
            }
        }
        
        return ans;
    }
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int minsteps=jump(nums);
    cout<<minsteps;
    return 0;
}