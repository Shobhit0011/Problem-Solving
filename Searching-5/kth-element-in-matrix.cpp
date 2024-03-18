 #include<bits/stdc++.h>
using namespace std;
int countlessthanmid(int mat[3][3], int mid, int row, int size) {
    int l = 0, h = size - 1, m;
    while (l <= h) {
        m = (l + h) / 2;
        if (mat[row][m] < mid) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return l;
}

int kthSmallest(int mat[3][3], int n, int k) {
    int l = mat[0][0], h = mat[n - 1][n - 1];
    while (l <= h) {
        int mid = l + (h - l) / 2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += countlessthanmid(mat, mid, i, n);
        }
        if (count < k) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return l-1; 
}
 int main(){
        int num1[3][3]={{1,2,3},{4,5,6},{7,8,9}};
        int ans=kthSmallest(num1,3,5);
        cout<<ans;
        return 0;
    }