// problem: 98. Validate Binary Search Tree
// difficulty: medium 
// topic: tree, bfs, dfs, BT
// approach: first of all we will do dfs because its easier and cleaner than bfs here, so for that we will make a validate function to do recursion, it will accept
// node, max value that node can have and min value, inside that function there willl be 2 conditions, 1- if node == null then return true else if value of node is
// greater than or equal to or less than equal to maxval and minval respectively then return false, and then if its opposite then return the recursion function of
// left and right nodes, updating the value or minVal and maxVal as required and continue this for all nodes, it will return true if its a valid bst,
// finally in isBst function, return the value of validate function having root, minVal and Maxval (set them as LLONG_MIN and LLONG_MAX for root node)
// time: O(n)
// space: O(h)
// link: https://leetcode.com/problems/validate-binary-search-tree/description/

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
    bool isValidBST(TreeNode* root) {
       return  validate(root, LLONG_MIN, LLONG_MAX);
    }
    bool validate(TreeNode* node,long long minVal,long long maxVal)
    {
        if(node == NULL)
        return true;
        if(node->val <= minVal || node->val >= maxVal)
        return false;

        return validate(node->left, minVal, node->val) 
            && validate(node->right, node->val, maxVal);
    }
};


