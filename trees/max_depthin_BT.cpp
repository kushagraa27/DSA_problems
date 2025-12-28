// problem: 104. Maximum Depth of Binary Tree
// difficulty: easy
// topic: tree, bfs, dfs, binary tree
// approach: if root is null then return 0 otherwise check the max depth of left if root and right of root and return 1 + max out of left depth and right depth.
// time: O(n)
// sapce: O(h) [h- hight of tree], worst case - O(n)
// link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        return 0;

        int leftdepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return 1+max(leftdepth,rightDepth);
    }
};
