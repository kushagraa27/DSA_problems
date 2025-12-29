// problem: 101. Symmetric Tree
// difficulty: easy
// topic: tree, dfs, bfs, binary tree
// approach: first of all we will make a function isMirror to check if the tree is symetric or not and to perform recursion in that, we have 3 base comditions, 1- if right = left = NULL then we will return true
// 2- if right or left is null but other one is not null then return false, 3- if value of right is not equal to value of left then return false, finally if both values are equal then we will do recusion,
// but further putting, left subtree and right subtree in the function again, and compare them. at last in isSymmetric function, we will check if root is null then return true or else put left and right of 
// root in isMirror and return its value.
// note: if we also included condition - if right value and left value are same return true then recusrion will not happen thats why we dont write it (its understood) and return true only when both are null 
// (no further nodes to explore)
// time: O(n)
// space: O(h)
// link: https://leetcode.com/problems/symmetric-tree/description/

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
    
        bool isMirror(TreeNode* left, TreeNode* right)
        {
            if(left==NULL && right==NULL)
            return true;
            if(left==NULL || right==NULL)
            return false;
            if(left->val != right->val)
            return false;

            return isMirror(left->left, right->right)
                    && isMirror(left->right, right->left);
        }
        bool isSymmetric(TreeNode* root) {
            if(root == NULL)
            return true;

            return isMirror(root->left,root->right);
    }
};

