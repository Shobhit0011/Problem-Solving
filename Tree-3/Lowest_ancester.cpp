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
    bool path(TreeNode* r,int target,vector<int>& ans){
        if(r==NULL)return 0;
         ans.push_back(r->val);
        if((r->val==target)||path(r->left,target,ans)||path(r->right,target,ans)){
           
            return 1;
        }
        ans.pop_back();
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)  {       vector<int>ans;
    vector<int > mns;
            bool a=path(root,p->val,ans);
            bool b=path(root,q->val,mns);
            int d;
            int i=0;
            while(i<ans.size()&& i<mns.size() && ans[i]==mns[i]){
                 d=ans[i];
                 i++;
            }
          TreeNode* answer=new TreeNode(d);
            return answer;
    }
    int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(9);
    root->right=new TreeNode(20);
    root->right->left=new TreeNode(15);
    root->right->right=new TreeNode(7);
    
    TreeNode* r=lowestCommonAncestor(root,root->right,root->left);
    cout<<r->val;
    return 0;
 }