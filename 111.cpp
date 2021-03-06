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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        
        int r=INT_MAX,l=INT_MAX;
        
        if(root->right)
            l = minDepth(root->right);
        if(root->left)
            r = minDepth(root->left);
        
        if(r==INT_MAX && l == INT_MAX) return 1;
        
        return 1 + min(l,r);
    }
};