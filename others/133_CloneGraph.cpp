/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;
        
        unordered_map<Node*, Node*> clone_map;
        queue<Node*> q;
        
        q.push(node);
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            if (clone_map.find(curr) == clone_map.end()) {
                // Create a clone for this node.
                Node *clone = new Node(curr->val);
                clone_map[curr] = clone;
            }
            // Add unvisited neighbor nodes.
            for (Node *tmp : curr->neighbors) {
                if (clone_map.find(tmp) == clone_map.end())
                    q.push(tmp);
            }
        }
        
        // Set neighbors of the clone nodes.
        for (pair<Node* const, Node*>& p : clone_map) {
            Node *old = p.first;
            Node *clone = p.second;
            for (Node *nbor : old->neighbors) {
                clone->neighbors.emplace_back(clone_map[nbor]);
            }
        }
        
        return clone_map[node];
    }
};
