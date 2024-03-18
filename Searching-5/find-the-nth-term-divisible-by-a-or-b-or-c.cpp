    #include<bits/stdc++.h>
    using namespace std;
    int gcd(int a, int b)
{
    if (a == 0)
        return b;
 
    return gcd(b % a, a);
}
   int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}
    int divisible(int a,int b,int c,int n) {
         int l=1,h=INT_MAX;
         while(l<=h){
            int m=(l+(h-l))/2;
            if(((m/a)+(m/b)+(m/c)-(m/lcm(a,b))-(m/lcm(b,c))-(m/lcm(a,c))+(m/lcm(a,lcm(b,c))))<n){
               l=m+1;
            }
            else{
                h=m;
            }
         }
         return l;
      
    }
    int main(){
       int a=2,b=3,c=4,n=10;
       int ans=divisible(a,b,c,n);
       cout<<ans;
       return 0;
    }
