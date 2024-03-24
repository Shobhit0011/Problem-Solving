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
void vertical(map<int,map<int,vector<int>>> &ans,Node* root,int x,int y){
        if(root==NULL)return;
        ans[x][y].push_back(root->data);
        vertical(ans,root->left,x-1,y+1);
        vertical(ans,root->right,x+1,y+1);
    }
    vector<int> topView(Node *root)
    {
          map<int ,map<int,vector<int>>> ans;
          vertical(ans,root,0,0);
          vector<int> top;
          vector<vector<int>> vert;
          for (auto col : ans) {
            vector<int> colVals;
            for (auto row : col.second) {
                sort(row.second.begin(), row.second.end());
                colVals.insert(colVals.end(), row.second.begin(), row.second.end());
            }
            vert.push_back(colVals);
        }
        for(auto i:vert){
            top.push_back(i[0]);
        }
          return top;
    }
 int main(){
    Node* root=new Node(3);
    root->left=new Node(9);
    root->right=new Node(20);
    root->right->left=new Node(15);
    root->right->right=new Node(7);
    
    vector<int> ans;
	ans=topView(root);
	cout<<"[";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<"]";
    return 0;
 }