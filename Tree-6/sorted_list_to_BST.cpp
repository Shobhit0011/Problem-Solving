#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  TreeNode* build(ListNode* a,int i,int j){
      if(i>j)return NULL;
      int m=(i+j)/2;
      ListNode* t=a;
      int p=0;
      while(p<m){
          a=a->next;
          p++;
      }
      TreeNode* root=new TreeNode(a->val);
      root->left=build(t,i,m-1);
      root->right=build(t,m+1,j);
      return root;
  }
    TreeNode* sortedListToBST(ListNode* head) {
        int size=0;
        ListNode* a=head;
        while(head!=NULL){
            size++;
            head=head->next;
        }
        return build(a,0,size-1);
    }
    void inor(TreeNode* r){
    if(r==NULL)return;
    inor(r->left);
    cout<<r->val<<" ";
    inor(r->right);
}
     int main(){
         ListNode* root=new ListNode(4);
         root->next=new ListNode(5);
         root->next->next=new ListNode(11);
         root->next->next->next=new ListNode(16);
         root->next->next->next->next=new ListNode(36);
        root->next->next->next->next->next=new ListNode(79);
         
        TreeNode* ans=sortedListToBST(root);
        inor(ans);
        return 0;
    }