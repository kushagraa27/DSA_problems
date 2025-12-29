// problem: 100. Same Tree
// difficulty: easy
// topics: tree, dfs, bfs, binary tree
// approach: first we will make a function called isSame for recursion and comparison of nodes, in thqat function there will be 3 base conditions, 1- if both values 
// are null then return true, 2- if only one of them is null then resturn false and 3- if values of both nodes is not same then return false, then we know that,
// if all 3 conditions are false it means, the value of nodes are same and theyr  not null so we will do resursion of those values keeping both right and left childs in
// mind. we will do comparison by putting again left and right childs of first and second node in our function, if both returns true then function returns true.
// time: O(n)
// space: O(h)
// link: https://leetcode.com/problems/same-tree/description/

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
bool isSame(TreeNode* LT, TreeNode* RT)
{
    if(LT == NULL && RT == NULL)
    return true;
    if(LT == NULL || RT == NULL)
    return false;
    if (LT->val != RT->val)
    return false;

    return isSame(LT->left, RT->left) && isSame(LT->right, RT->right);
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSame(p,q);
    }
};
