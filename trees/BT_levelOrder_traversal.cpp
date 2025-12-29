// problem: 102. Binary Tree Level Order Traversal
// difficulty: medium 
// topic: tree, binary tree, bfs
// approach: so first of all we will create a vector of vectors to store the result and make a queue for bfs operation, then we will push the root in our queue, and 
// start a while loop till queue is not empty, inside that first we will make a vector named level to store all vales of nodes in that particular level, and we will
// also store the size of the queue so that we will know till which element in queue we need to run the for loop, this prevents us going to other level of grandchildren
// then we will start a for loop from 0 to size of queue at that time and then we will store then front of queue in a pointer and pop the front, the stored front value 
// will be pushed back to the level vector and we will store the node->left and node->right in the queue if exixts and this will keep going till the for loop ends 
// when for loop ends we will get all elements at a level and we will push them to our result vector of vectors, then while loop will continue and new queue size and
// level will be again initialised. and at last all values will be stored in result, breath wise. finally return the result after while loop ends.
// time: O(n)
// space: O(n)
// link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            vector<int> level;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }        
            result.push_back(level);
        }
            return result;
    }
};
