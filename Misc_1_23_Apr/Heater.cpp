#include<bits/stdc++.h>
using namespace std;
    bool ispossible(vector<int>& a,vector<int>& b,int r)
    {
        int i=0,j=0;
        while(i<b.size())
        {
            if(j==a.size())return false;
            int hpos=a[j++];
            int lpos=hpos-r;
            int rpos=hpos+r;
            while(i<b.size()&&b[i]>=lpos&&b[i]<=rpos)
                i++;
        }
        return true;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int n=houses.size();
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        long long l=0,ans=-1,h=INT_MAX;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(ispossible(heaters,houses,m))
            {
                ans=m;
                h=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
    int main(){
        vector<int> house={1,2,3};
        vector<int> heaters={2};
        int rad=findRadius(house,heaters);
        cout<<rad;
        return 0;
    }
