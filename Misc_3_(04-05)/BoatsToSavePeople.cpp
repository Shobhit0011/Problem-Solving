#include<bits/stdc++.h>
using namespace std;
int Rescueboats(vector<int>& people, int limit) {
    sort(people.begin(),people.end());
    int i,j,ans=0;
    for(i=0,j=people.size()-1;i<j;){
      if(people[i]+people[j]<=limit){
          ans++;
          i++;
          j--;
      }
      if(people[i]+people[j]>limit){
          ans++;
          j--;
      }
    }
    if(i==j)ans++;
    return ans;
}
int main(){
  vector<int> people={3,2,2,1};
  int limit=3;
  int ans=Rescueboats(people,limit);
  cout<<ans;
return 0;
}
