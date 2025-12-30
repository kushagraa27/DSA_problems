// problem: 133. Clone Graph
// difficulty: medium
// topics: hash table, bfs, dfs, graphs 
// approach: first we made a unordered map to prevent infinite loop in map due to cycles, we declared it globally so that it dont gets changed inside our recursion function again n again, inside our function,
// we will first check if the node is null, return null if true, then we will check if the node is alredy present in our map, if yes then we will not make a new node, we will just reuse that old node and thats how
// cyclic problem is solved, preventing infinite loop using hash map, then if that node is not already present in our map then we will make a new node named clone and add it to map as well, then finally 
// to make it recursive, we will start a for loop iterating through all neighbours of first node and coming nodes after it, we will pushback to the neighbours of clone, the value of cloneGraph(neighbour) which 
// again checks all conditins and return the node accordingly, at last return the clone.
// time: O(n)
// space: O(n)
// link:  https://leetcode.com/problems/clone-graph/description/

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
    unordered_map<Node*, Node*> mp;
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;

        if(mp.find(node)!=mp.end())
        return mp[node];

        Node* clone = new Node(node->val);
        mp[node] = clone;

        for(Node* neighbor : node->neighbors){
            clone->neighbors.push_back(cloneGraph(neighbor));
            }

            return clone;
    }
};
