#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = nullptr; // for 0 bit
        child[1] = nullptr; // for 1 bit
    }
};

    TrieNode* newNode;

      string getBits(int x) {
        string s = "";
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            s.push_back(bit + '0');
        }
        return s;
    }

    void insert(int x) {
        TrieNode* t = newNode;
        string bits = getBits(x);
        for (int j = 0; j < bits.size(); j++) {
            if (!t->child[bits[j] - '0']) {
                t->child[bits[j] - '0'] = new TrieNode();
            }
            t = t->child[bits[j] - '0'];
        }
    }

    int maxXOR(int n) {
        TrieNode* t = newNode;
        string bits = getBits(n);
        int ans = 0;
        for (int j = 0; j < bits.size(); j++) {
            if (t->child[1 - (bits[j] - '0')]) { 
                ans += (1 << (31-j));
                t = t->child[1 - (bits[j] - '0')];
            } else {
                t = t->child[bits[j] - '0'];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        newNode = new TrieNode();
        for (auto& n : nums) {
            insert(n);
        }

        int ans = 0;
        for (auto n : nums) {
            ans = max(ans, maxXOR(n));
        }
        return ans;
    }

      int main(){
        vector<int> nums={14,70,53,83,49,91,36,80,92,51,66,70};
        int ans=findMaximumXOR(nums);
            cout<<ans<<"\n";
    }
