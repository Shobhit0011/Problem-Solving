#include<bits/stdc++.h>
using namespace std;
int maximumBooks(vector<int>& BooksatA,vector<int>& BooksatB, int K) {
    sort(BooksatA.begin(), BooksatA.end());
    sort(BooksatB.begin(), BooksatB.end());

    int idxA = 0, idxB = 0; 
    int totalTime = 0;
    int books = 0; 
    while (idxA < BooksatA.size() && idxB < BooksatB.size() && totalTime < K) {
        if (BooksatA[idxA] < BooksatB[idxB]) {
            if (totalTime + BooksatA[idxA] > K) 
                break;
            totalTime += BooksatA[idxA++];
        } 
        else {
            if (totalTime + BooksatB[idxB] > K) 
                break;
            totalTime += BooksatB[idxB++];
        }
        books++;
    }
    while (idxA < BooksatA.size() && totalTime + BooksatA[idxA] <= K) {
        totalTime += BooksatA[idxA++];
        books++;
    }
    while (idxB < BooksatB.size() && totalTime + BooksatB[idxB] <= K) {
        totalTime += BooksatB[idxB++];
        books++;
    }

    return books;
}

int main() {
    int K,n,m ;
    cout<<"enter"<<"\n";
    cin>>n>>m>>K; // 3 4 200
     vector<int> BooksatA(n) ; 
    vector<int> BooksatB(m);
    cout<<"Enter books of BooksatA:\n";
    for(int i=0;i<n;i++){
      cin>>BooksatA[i];
    }// 60 50 120
    cout<<"Enter books of BooksatB:\n";
    for(int i=0;i<m;i++){
      cin>>BooksatB[i];
    }// 40 110 80 150
    int result = maximumBooks(BooksatA, BooksatB, K);
    cout << "Maximum number of books read: " << result <<endl;

    return 0;
}
