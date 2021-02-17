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
    
    TreeNode* buildTree(vector<int>& pre, int& preIdx,unordered_map<int,int> &mp,int st,int en){
        if(st>en) return NULL;
        
        TreeNode* root = new TreeNode(pre[preIdx++]);
        if(st == en) return root;
        
        root->left = buildTree(pre,preIdx,mp,st,mp[root->val]-1);
        root->right = buildTree(pre,preIdx,mp,mp[root->val]+1,en);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]] = i;
        
        int n =0;
        
        return buildTree(preorder,n,mp,0,inorder.size()-1);
    }
};