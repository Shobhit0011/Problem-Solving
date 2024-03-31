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
void inorder(vector<int>& an,Node* r){
    if(r==NULL)return;
    inorder(an,r->left);
    an.push_back(r->val);
    inorder(an,r->right);
}
    bool isValidBST(Node* root) {
        vector<int> an;
        inorder(an,root);
        for(int i=0;i<an.size()-1;i++){
            if(an[i]>=an[i+1])return 0;
        }
        return 1;
    }
    
  int main(){
    Node* root=new Node(7);
    root->left=new Node(5);
    root->right=new Node(10);
    root->right->left=new Node(9);
    root->right->right=new Node(11);
    bool ans=isValidBST(root);
   if(ans){
    cout<<"VALID BST";
   }
   else{
    cout<<"NOT VALID BST";
   }
    return 0;
 }
