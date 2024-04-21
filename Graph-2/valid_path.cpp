
#include <bits/stdc++.h>
using namespace std;

bool check(int& x1,int& y1,vector<pair<int,int>>& cir,int& r)
{
    for(auto it:cir)
    {
        int x2=it.first;
        int y2=it.second;
        int x=abs(x1-x2);
        int y=abs(y1-y2);
        x*=x;
        y*=y;
        if(x+y<=r*r)
        return true;
    }
    return false;
}
bool solv(int i,int j,int dirx[],int diry[],vector<pair<int,int>>& cir,vector<vector<int>>&vis,int&x,int&y,int& r)
{
    if(i<0||j<0||i>x||j>y||vis[i][j]==1||check(i,j,cir,r))
    return false;
    if(i==x&&j==y)
    return true;
    vis[i][j]=1;
    for(int dir=0;dir<8;dir++)
    {
        int newi=dirx[dir]+i;
        int newj=diry[dir]+j;
        if(solv(newi,newj,dirx,diry,cir,vis,x,y,r))
        return true;
    }
    return false;
}
string solve(int x, int y, int N, int R, vector<int> &X, vector<int> &Y) {
    int dirx[]={1,1,1,-1,-1,-1,0,0};
    int diry[]={1,0,-1,1,0,-1,1,-1};
    vector<pair<int,int>> cir;
    for(int i=0;i<N;i++)
    cir.push_back({X[i],Y[i]});
    vector<vector<int>> vis(x+1,vector<int>(y+1,-1));
    return solv(0,0,dirx,diry,cir,vis,x,y,R)?"YES":"NO";
}
int main(){
    int N,x,y,rad;
    cout<<"Enter x and y-coordinate of destination: ";
    cin>>x>>y;
    cout<<"Enter number of circles:";
    cin>>N;
    cout<<"\n";
    cout<<"Enter radius of circles:";
    cin>>rad;
    cout<<"\n";
    vector<int> cirX(N);
    vector<int> cirY(N);
    cout<<"Enter x-coordinates of circles center:\n";
    for(int i=0;i<N;i++){
        cin>>cirX[i];
    }cout<<"\nEnter y-coordinates of circles center:\n";
    for(int i=0;i<N;i++){
        cin>>cirY[i];
    }
    string ans=solve(x,y,N,rad,cirX,cirY);
    cout<<ans;
    return 0;
}