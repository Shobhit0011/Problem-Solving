#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
    bool isEnd=0;
    int count=0;
    trienode* children[26];
};
void insert(string word,trienode* root) {
        trienode* node=root;
        for(char i:word){
            if(!node->children[i-'a']){
                node->children[i-'a']=new trienode();
            }
            node=node->children[i-'a'];
            node->count+=1;
        }
        node->isEnd=1;
    }
    
    int search(string word,trienode* root) {
        int score=0;
        trienode* node=root;
        for(char c:word){
            if(!node->children[c-'a']){
                return 0;
            }
            node=node->children[c-'a'];
            score+=node->count;
        }
        return score;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        trienode* root=new trienode();
        vector<int> ans;
        for(auto w:words){
            insert(w,root);
        }
        for(auto w:words){
            int s=search(w,root);
            ans.push_back(s);
        }
    return ans;
    }
    int main(){
        vector<string> words={"abc","ab","bc","b"};
        vector<int> ans=sumPrefixScores(words);
        for(int i:ans){
            cout<<i<<" ";
        }
    }
