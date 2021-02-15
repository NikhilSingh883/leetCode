/*
// Definition for a Node.
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
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        map<Node*,Node*> m;
        m[node] = new Node(node->val);
        queue<Node*> Q;
        set<Node*> S;
        
        S.insert(node);
        Q.push(node);
        
        while(!Q.empty()){
            Node* ptr = Q.front();
            Q.pop();
            
            for(int i=0;i<ptr->neighbors.size();i++){
                if(m.count(ptr->neighbors[i]))
                    m[ptr]->neighbors.push_back(m[ptr->neighbors[i]]);
                else {
                    m[ptr->neighbors[i]] = new Node(ptr->neighbors[i]->val);
                    m[ptr]->neighbors.push_back(m[ptr->neighbors[i]]);
                }
                if(S.count(ptr->neighbors[i]) == 0){
                    Q.push(ptr->neighbors[i]);
                    S.insert(ptr->neighbors[i]);
                }
            }
        }
        
        return m[node];
    }
};