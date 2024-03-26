 #include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
 bool path(Node* r,int target,vector<int>& ans){
        if(r==NULL)return 0;
         ans.push_back(r->data);
        if((r->data==target)||path(r->left,target,ans)||path(r->right,target,ans)){
           
            return 1;
        }
        ans.pop_back();
        return 0;
    }
    int findDist(Node* root, int a, int b) {
          vector<int>ans;
    vector<int > mns;
            bool av=path(root,a,ans);
            bool bv=path(root,b,mns);
            int d=0;
            int i=0;
            while(i<ans.size()&& i<mns.size() && ans[i]==mns[i]){
                 d++;
                 i++;
            }
            int ans1=(ans.size()-d)+(mns.size()-d);
            return ans1;
    }
     int main(){
    Node* root=new Node(3);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    
    int r=findDist(root,7,15);
    cout<<r;
    return 0;
 }