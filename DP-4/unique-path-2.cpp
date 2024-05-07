#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int path(vector<vector<int>>& arr,int i,int j,vector<vector<int>>& memo){
        if(i>=arr.size() || j>=arr[0].size())return 0;
        if(i<arr.size() && j<arr[0].size() && arr[i][j]==1)return 0;
        if(i==arr.size()-1 && j==arr[0].size()-1)return 1;
        if(memo[i][j]!=-1)return memo[i][j];
        int ri=path(arr,i+1,j,memo);
        int dow=path(arr,i,j+1,memo);
        return memo[i][j]=ri+dow;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> memo(obstacleGrid.size()+1,vector<int>(obstacleGrid[0].size()+1,-1));
        int ans=path(obstacleGrid,0,0,memo);
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> arr={{1,2,3},{4,5,9},{11,22,12}};

    int ans=s.uniquePathsWithObstacles(arr);
    cout<<ans;
    return 0;
}