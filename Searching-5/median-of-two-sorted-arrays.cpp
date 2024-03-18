    #include<bits/stdc++.h>
    using namespace std;
    double findMedian(vector<int>& arr1, vector<int>& arr2) {
       int m=arr1.size();
       int n=arr2.size();
       float a[2000];
       int i;
       float median;
       for(i=0;i<m||i<n;i++){
           if(i<m)
           a[i]=arr1[i];
           if(i<n)
           a[m+i]=arr2[i];
       } 
       sort(a,a+(m+n));
       if((m+n)%2==0)
        median=(a[(m+n)/2]+a[((m+n)/2)-1])/2;
        else if((m+n)%2!=0)
        median=a[(m+n)/2];
        return med;
    }
    int main(){
        vector<int> num1={3,4,5,6,7,8,9,10};
        vector<int> num2={23,24,51,76,98};
        double ans=findMedian(num1,num2);
        cout<<ans;
    }
