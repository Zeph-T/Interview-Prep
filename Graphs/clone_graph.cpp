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
    unordered_map<Node* , Node* >mp;


    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;
        if(mp.find(node) == mp.end()){ // if the node is not cloned we create the new node and map to the original node such that, we can get the address of the clone node
                                        // with the original node
            mp[node] = new Node(node->val);
        }else return mp[node];
        
        for(auto nbr : node->neighbors){
            mp[node]->neighbors.push_back(cloneGraph(nbr));
        }
        return mp[node];
        
    }
};