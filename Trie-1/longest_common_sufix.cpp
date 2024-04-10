#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
    int idx=INT_MAX;
    int min_s=INT_MAX;
    trienode* children[26];
     trienode() {
        for (auto &a : children) a = nullptr;
    }
};
void insert(string word,trienode* root,int i) {
    trienode* node=root;
    for(int j=word.size()-1;j>=0;j--){
        if(!node->children[word[j]-'a']){
             node->children[word[j]-'a']=new trienode();
        }
        node=node->children[word[j]-'a'];
        if(word.size()<node->min_s){
            node->min_s=word.size();
            node->idx=i;
        }
    }
}  
int startsWith(string prefix,trienode* root) {
    trienode* node=root;
    for(int i=prefix.size()-1;i>=0;i--){
        if(!node->children[prefix[i]-'a']){
           break;
        }
        node=node->children[prefix[i]-'a'];
    }
    return node->idx;
}

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trienode* root=new trienode();
        vector<int> ans;
        int ind=-1;
        int mni=INT_MAX;
        for(int i=0;i<wordsContainer.size();i++){
            if(mni>wordsContainer[i].size()){
                ind=i;
                mni=wordsContainer[i].size();
            }
            insert(wordsContainer[i],root,i);
        }
        for(int i=0;i<wordsQuery.size();i++){
           int j=startsWith(wordsQuery[i],root);
           if(j==INT_MAX) {j=ind;}
           ans.push_back(j);
        }

        return ans;
    }
int main(){
    vector<string> words={"abcd","bcd","xbcd"};
    vector<string> wordsQuery={"cd","bcd","xyz"};
    vector<int> a=stringIndices(words,wordsQuery);
    cout<<"Answer is:\n";
    for(int i:a){
        cout<<i<<" ";
    }
}