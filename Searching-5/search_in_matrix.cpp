      #include<bits/stdc++.h>
    using namespace std;
    bool searchMatrix(vector<vector<int>>& mat, int target) {
       int l=0,h=mat.size()-1;
       while(l<=h){
         int m=l+(h-l)/2;
         if(target<mat[m][0]){
            h=m-1;
         }
         else{
            l=m+1;
         }
       }
        int row = h; 
        if (row < 0) return false;
        int a = 0, b = mat[row].size() - 1;
        while (a <= b) {
            int m = a + (b - a) / 2;
            if (target == mat[row][m]) return true; 
            else if (target > mat[row][m]) { 
                a = m + 1;
            } else {
                b = m - 1;
            }
        }
        return false;
    }
     int main(){
        vector<vector<int>> num1={{1,2,3},{4,5,6},{7,8,9}};
        bool ans=searchMatrix(num1,3);
        if(ans)cout<<"Found!";
        else cout<<"Not Found!!";
        return 0;
    }

