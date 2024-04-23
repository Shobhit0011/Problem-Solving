#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// Make a clone of a graph...

  Node* cloneGraph(Node* node) {
        if(!node)return NULL;
        unordered_map<Node*,Node*> clone;
        queue<Node*> q;
        Node* ans=new Node(node->val);
        q.push(node);
        clone[node] = new Node(node->val);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
           
           for (Node* neighbor : curr->neighbors) {
                if (!clone.count(neighbor)) {
                   
                    clone[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                clone[curr]->neighbors.push_back(clone[neighbor]);
           }
        }
        return clone[node];
    }

//  main function...

int main(){
  return 0;
}
