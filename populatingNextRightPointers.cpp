/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root || (!root->right && !root->left)) return root;

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* cur = q.front();
                q.pop();
                if(i==n-1) cur->next = NULL;
                else cur->next = q.front();

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }

        return root;
    }
};