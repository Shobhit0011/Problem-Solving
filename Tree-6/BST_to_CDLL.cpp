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
 Node* head=NULL;
    Node* prevo=NULL;
    void inorder(Node* root){
        if(root==NULL)return;
        inorder(root->left);
        if(head==NULL)head=root;
        else{
            root->left=prevo;
            prevo->right=root;
        }
        prevo=root;
        inorder(root->right);
    }
    Node *bTreeToCList(Node *root)
    {
      inorder(root);
      head->left=prevo;
      prevo->right=head;
      return head;
    }
      int main(){
         Node* root=new Node(5);
         root->left=new Node(3);
         root->right=new Node(7);
         root->left->left=new Node(2);
         root->left->right=new Node(4);
         root->right->left=new Node(6);
         root->right->right=new Node(16);
         Node* head=bTreeToCList(root);
         Node* tem=head;
         cout<<tem->data<<" ";
         tem=tem->right;
        while(tem!=head){
            cout<<tem->data<<" ";
            tem=tem->right;
        }
        return 0;
    }