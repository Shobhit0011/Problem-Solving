 #include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
int ceil(Node *r, int x, int ans) {
       
     if(r==NULL){
         return ans;
     }
       if(r->val==x){
           return x;
       }
       if(r->val<x){
             return ceil(r->right,x,ans);
       }
       if(r->val>x){
           ans=r->val;
           return ceil(r->left,x,ans);
       }
       return ans;
}
int findCeil(Node* root, int input) {
    return ceil(root,input,-1);
}
  int main(){
    Node* root=new Node(7);
    root->left=new Node(5);
    root->right=new Node(10);
    root->right->left=new Node(9);
    root->right->right=new Node(11);
    int ans=findCeil(root,8);
   cout<<" "<<ans<<" ";
    return 0;
 }