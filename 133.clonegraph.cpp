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
    unordered_map<Node*, Node*> oldToNew;
    Node* cloneGraph(Node* node) {
        // 0. take care of corner case
        if (node ==  NULL)
            return NULL;
        
        // 1. check if it's already on the hashmap (already cloned, return the cloned node)
        if (oldToNew.find(node) != oldToNew.end())
            return oldToNew[node];
        
        // 2. clone the value and put it into the hashmap
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;
        
        // 3. clone the neighbors 
        for (Node* nei: node->neighbors) {
            copy->neighbors.push_back(cloneGraph(nei));
        }
        
       return copy; //oldToNew[node]
        
    }
};

        /* python version
        # 0. take care of corner case
        if (node is None):
            return None

        oldToNew = {}
    
        def clone(node):
            # 1. check if it's already on the hashmap (already cloned)
            if (node in oldToNew):
                return oldToNew[node]
            
            # 2. clone the node val and add to the hashmap
            copy = Node(node.val)
            oldToNew[node] = copy
                
            # 3. clone the neighbors    
            for nei in node.neighbors:
                copy.neighbors.append(clone(nei))
            return copy
            
        return clone(node)
        */
