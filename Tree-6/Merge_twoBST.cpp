#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
 void mer(Node* r1,vector<int>& ans){
        if(r1==NULL)return;
        mer(r1->left,ans);
        ans.push_back(r1->data);
        mer(r1->right,ans);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
         vector<int> ans1;
         vector<int> ans2;
         mer(root1,ans1);
         mer(root2,ans2);
         vector<int> ans;
         int i,j;
         for(i=0,j=0;i<ans1.size()&&j<ans2.size();){
             if(ans1[i]<=ans2[j]){
                 ans.push_back(ans1[i]);
                 i++;
             }
             else if(ans1[i]>ans2[j]){
                 ans.push_back(ans2[j]);
                 j++;
             }
         }
         while(i < ans1.size()) {
               ans.push_back(ans1[i]);
               i++;
             }
          while(j < ans2.size()) {
              ans.push_back(ans2[j]);
              j++;
         }
         return ans;
    }
    int main(){
        // 1st TREE......
         Node* root=new Node(8);
         root->left=new Node(4);
         root->right=new Node(11);
         root->left->left=new Node(2);
         root->left->right=new Node(6);
         root->right->left=new Node(9);
         root->right->right=new Node(16);
         // 2nd TREE.....
         
          Node* root1=new Node(7);
         root1->left=new Node(3);
         root1->right=new Node(10);
         root1->left->left=new Node(1);
         root1->left->right=new Node(5);
         root1->right->left=new Node(8);
         root1->right->right=new Node(15);
         vector<int> ans=merge(root,root1);
         for(int i:ans){
            cout<<i<<" ";
         }
        return 0;
    }