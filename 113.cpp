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
    vector<vector<int>> ans;
    void pathUtil(TreeNode* root,int targetSum,vector<int> tar){
        if(!root) return;
        
        if(!root->right && !root->left){
            if(targetSum - root->val ==0){
                tar.push_back(root->val);
                ans.push_back(tar);
            }
            return;
        }
        
        tar.push_back(root->val);
        pathUtil(root->left,targetSum - root->val,tar);
        tar.pop_back();
        
        tar.push_back(root->val);
        pathUtil(root->right,targetSum - root->val,tar);
        tar.pop_back();
        
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ans.clear();
        vector<int> tar;
        pathUtil(root,targetSum,tar);
        return ans;
    }
};