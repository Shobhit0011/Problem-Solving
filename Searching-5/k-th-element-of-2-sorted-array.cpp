    #include<bits/stdc++.h>
    using namespace std;
    int cnt(vector<int> a,int mid,int size){
        int l=0,h=size-1;
        while(l<=h){
            int m=(l+h)/2;
            if(a[m]==mid){
                return m-1;
            }
            else if(a[m]<mid){
                h=m-1;      
            }
            else{
                l=m+1;
            }
        }
        return 0;
    }
    int kth(vector<int> nums1,vector<int> nums2,int k) {
       int l=min(nums1[0],nums2[0]);
       int h=max(nums1[nums1.size()-1],nums2[nums2.size()-1]);
       int ans;
       while(l<=h){
        int m=l+(h-l)/2;
        int c=cnt(nums1,m,nums1.size());
        c+=cnt(nums2,m,nums2.size());
        if(c<k){
            l=m+1;
        }
        else if(c>k){
            h=m;
        }
        else{
           ans=m;
           l=m+1;
        }
       }
       return ans;
    }
    int main(){
        vector<int> nums1={2,3,9,10};
        vector<int> nums2={4,6,7,8};
        int k=3;
        int ans=kth(nums1,nums2,k);
        cout<<ans;
    }
