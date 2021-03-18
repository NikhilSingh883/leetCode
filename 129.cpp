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
    vector<int> nums;
    void numbers(TreeNode* root,int num){
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            num = num*10 + root->val;
            nums.push_back(num);
            return;
        }
        
        numbers(root->left,num*10 + root->val);
        numbers(root->right,num*10 + root->val);

    }
    int sumNumbers(TreeNode* root) {
        nums.clear();
        numbers(root,0);
        
        int ans =0;
        for(int i=0;i<nums.size();i++) ans += nums[i];
        
        return ans;
    }
};