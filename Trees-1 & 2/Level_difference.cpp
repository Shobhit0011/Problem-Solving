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
    int ord(Node* r, int c){
         if(r == NULL){
             return 0;
         }
         if(c % 2 == 0){
             return r->data + ord(r->left, c+1) + ord(r->right, c+1);
         }
         else{
             return -r->data + ord(r->left, c+1) + ord(r->right, c+1);
         }
     }
    int getLevelDiff(Node *root)
    {
       return ord(root, 0);
    }
    int main()
{
	Node* root =new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(6);
	root->right->left = new Node(5);
	root->right->right = new Node(7);
	root->right->left->right = new Node(8);
	root->right->right->right = new Node(9);
	int a=getLevelDiff(root);
    cout<<a;
	return 0;
}