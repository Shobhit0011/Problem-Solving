#include<bits/stdc++.h>
using namespace std;
    int equalSubstring(string s, string t, int maxCost) {
        int temp = 0;
        int ans=0;
        for (int i = 0, j = 0; s[i]!='\0'; i++) {

            temp+=abs(s[i]-t[i]);

            if(temp<=maxCost)
            {
                ans=max(ans,i-j+1);
            }
            else
            {
                while(temp>maxCost)
                {
                    temp=temp-abs(s[j]-t[j]);
                    j++;
                }
            }
        }

        return ans;
    }
    int main(){
        string s="abcd",t="defg";
        int m=2;
        int ans=equalSubstring(s,t,m);
        cout<<"Answer:  "<<ans;
    }