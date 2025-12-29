// problem: 199. Binary Tree Right Side View
// difficulty: medium
// topics: BT, BFS, DFS, trees
// approach: this is like bt level order traversal only but here instead of picking up every node at each level, we just need to pick the last node of a particular 
// level, which is the rightmost node, pick it and store it in result vector and at last returnt hat result vector to get desired output.
// time: O(n)
// space:O(n)
// link:  https://leetcode.com/problems/binary-tree-right-side-view/description/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {   
            int lastval;
            int size = q.size();
            for(int i =0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                lastval = node->val;
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            result.push_back(lastval);
        }
        return result;
    }
};
