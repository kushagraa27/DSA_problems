// problem: 543. Diameter of Binary Tree
// difficulty: easy
// topics: BT, trees, dfs
// approach: so the working of this problem is same as maximum depth in Bt problem, but we just add one more global variable called diameter which helps us to store
// the maximum path length at each node, and not just root and we return it at last.
// time:O(n)
// space: O(h), balanced tree - O(log n), worst case (skewed tree) - O(n)
// link: https://leetcode.com/problems/diameter-of-binary-tree/description/

class Solution {
public:
    int diameter = 0;
    int Depth(TreeNode* node)
    {   
        if(node==NULL) return 0;
        int leftheight = Depth(node->left);
        int rightheight = Depth(node->right);

        diameter = max(diameter, leftheight+rightheight);

        return 1+max(leftheight,rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        Depth(root);
        return diameter;
    }
};

