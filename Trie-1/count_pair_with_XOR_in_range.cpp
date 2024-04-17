#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* child[2];
    int count=0;
    TrieNode() {
        child[0] = nullptr;
        child[1] = nullptr; 
    }
};
      string getBits(int x) {
        string s = "";
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            s.push_back(bit + '0');
        }
        return s;
    }
     void insert(TrieNode* newNode,int x) {
        TrieNode* t = newNode;
        string bits = getBits(x);
        for (int j = 0; j <=31; j++) {
            if (!t->child[bits[j] - '0']) {
                t->child[bits[j] - '0'] = new TrieNode();
            }
            t->child[bits[j]-'0']->count+=1;
            t = t->child[bits[j] - '0'];

        }
    }
    int count(TrieNode* root,int n,int k){
        string bits=getBits(n);
        string ki=getBits(k);
        int c1=0;
         for(int i=0;i<=31 && root;i++){
                if(ki[i]=='0'){
                    root=root->child[bits[i]-'0'];
                    continue;
                }
                if(root->child[bits[i]-'0']){
                    c1+=root->child[bits[i]-'0']->count;
                }
                root=root->child[1-(bits[i]-'0')];
            }
            return c1;
    }
    int countPairs(vector<int>& nums, int low, int high) {
        int cnt=0;
        TrieNode* newNode=new TrieNode();
        for(int i:nums){
            cnt+=count(newNode,i,high+1)-count(newNode,i,low);
            insert(newNode,i);
        }
    return cnt;
    }
int main(){
    int n;
    cout<<"Enter number of elements:\n";
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int low,high;
    cout<<"Enter range:\n";
    cin>>low>>high;
    int ans=countPairs(nums,low,high);
    cout<<ans;
    return 0;
}
