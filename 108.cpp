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
    
    TreeNode* util(vector<int>&nums,int st,int en){
        if(st>en) return NULL;
        
        int mid = (st+en)/2;
        
        TreeNode* root = new TreeNode();
        
        root->val = nums[mid];
        root->left = util(nums,st,mid-1);
        root->right = util(nums,mid+1,en);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        
        return util(nums,0,n-1);
    }
};