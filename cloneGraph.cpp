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
        if(node==NULL){
            return NULL;
        }
        Node* clone = new Node(node->val);
        map<Node*,Node*> map;
        queue<Node*> q;
        map[node] = clone;
        q.push(node);

        while(!q.empty()){

            Node* cur = q.front();
            q.pop();

            for(Node* i:cur->neighbors){
                if(map.find(i) == map.end()){
                    Node* temp = new Node(i->val);
                    map[i] = temp;
                    q.push(i);
                }

                map[cur]->neighbors.push_back(map[i]);
            }
        }

        return clone;
    }
};