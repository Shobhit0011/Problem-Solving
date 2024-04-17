#include<bits/stdc++.h>
using namespace std;
class TrieNode {
public:
    int no_of_ind;
    int idx_sum;
    TrieNode* child[2];
    
    TrieNode() : no_of_ind(0), idx_sum(0) {
        child[0] = NULL;
        child[1] = NULL;
    }
};
 void addNumber(TrieNode* root, int num, int idx){
        for( int i = 31; i >= 0; i--){
       
            int bit = 1 & (num >> i) ;
        
            if ( root->child[bit] == NULL){
                root->child[bit] = new TrieNode();
            }
            root = root->child[bit];
        }
        root->idx_sum += idx;
        root->no_of_ind++;
    }
    int calculateIndexPair(TrieNode* root, int num, int idx){
        for( int i = 31; i >= 0; i--){
            int bit = 1 & (num >> i);
        
            if (root->child[bit] == NULL){
                return 0;
            }
            root = root->child[bit];
        }
        return (((root->no_of_ind) * idx) - (root->idx_sum));
    }
    int countTriplets(vector<int>& arr) {
        long long ans=0;
        int XOR = 0;
        TrieNode* root = new TrieNode();
    
        for ( int i = 0 ; i < arr.size(); i++){
            addNumber(root, XOR, i);
            XOR ^= arr[i];
            ans = (ans + calculateIndexPair(root, XOR, i)) % 1000000007;
        }
        return ans;
    }
    int main(){
        int n;
        cout<<"Enter no of Element:- ";
        cin>>n;
        cout<<"enter all elements:-  \n";
        vector<int> arr(n);
        for(int i=0;i<n;i++){
           cin>>arr[i];
        }
        int ans=countTriplets(arr);
        cout<<ans;
        return 0;
    }
