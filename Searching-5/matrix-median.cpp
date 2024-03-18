    #include<bits/stdc++.h>
    using namespace std;
    float matrixmedian(vector<vector<int>>& nums1) {
        vector<int> n;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums1[i].size();j++){
                    n.push_back(nums1[i][j]);
            }
        }
        sort(n.begin(),n.end());
        if(n.size()%2==0){
            return (n[n.size()/2]+n[(n.size()-1)/2])/2;
        }
        return n[n.size()/2];
    }
    int main(){
        vector<vector<int>> num1={{1,2,3},{4,5,6},{7,8,9}};
        double ans=matrixmedian(num1);
        cout<<ans;
    }
