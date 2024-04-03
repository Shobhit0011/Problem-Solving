#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int sumfind(TreeNode* root,int &min,int &max,bool &isBST,int &max_sum)
    {
        if(!root){
            isBST=1;
            return 0;
        }
        int tmp=INT_MAX; 
        bool leftBST=false,rightBST=false; 
        max=INT_MIN; 
        int lsum=0;
        lsum+=sumfind(root->left,min,max,isBST,max_sum);
     
        if(isBST && root->val > max)  
           leftBST=true;
        tmp=min;
        min=INT_MAX;
        int rsum=0;
        rsum+=sumfind(root->right,min,max,isBST,max_sum);
      
        if(isBST && root->val < min)
          rightBST=true;
           
        if(tmp<min)
          min=tmp;
        if(root->val <min)
          min=root->val;
        if(root->val > max)
          max = root->val;
        if(leftBST && rightBST)
        {
            if(lsum + rsum + 1 > max_sum)
               max_sum=lsum + rsum + 1 ;
           return lsum + rsum + 1 ; 
        }
        else{
            isBST=0;
            return 0;
        }
    }
    int maxSumBST(TreeNode* root) {
        int min=INT_MAX;
        int max=INT_MIN;
        bool isBST=0;
        int max_sum=0;
        sumfind(root,min,max,isBST,max_sum);
        return max_sum;
    }
     int main(){

    TreeNode* root=new TreeNode(8);
    root->left=new TreeNode(6);
    root->right=new TreeNode(11);
    root->right->left=new TreeNode(10);
    root->right->right=new TreeNode(12);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(9);

    int ans=maxSumBST(root);
    
    cout<<ans<<" ";
    return 0;
 }