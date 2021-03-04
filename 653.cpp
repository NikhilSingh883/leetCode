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
    bool findTarget(TreeNode* root, int k) {
        if(!root) return NULL;
    
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,int> mp;

        while(!q.empty()){
            TreeNode* t = q.front();
            q.pop();

            if(mp.count(k-t->val)>0) return true;

            mp[t->val] = 1;

            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        return false;
    }
};