#include<bits/stdc++.h>
using namespace std;

    int maxSum(int N, vector<vector<int>> mat)
    {
    int in = max(mat[0][0], mat[1][0]);
    int prev = 0, next;

    for (int i = 1; i < N; i++) {
        next = max(prev, in);
        in = prev + max(mat[0][i], mat[1][i]);
        prev = next;
    }

    return max(prev, in);
    }

int main(){
    vector<vector<int>> mat={{1, 4, 5}, 
       {2, 0, 0}};
    
    int sum=maxSum(3,mat);
    cout<<sum;
    return 0;

}