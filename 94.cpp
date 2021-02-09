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
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(!root) return {};
        vector<int> ans;
        unordered_map<TreeNode*,int> cnt;
        
        stack<TreeNode*> in;
        
        in.push(root);
        
        while(!in.empty()){
            TreeNode* curr = in.top();
            
            if(curr == NULL){
                in.pop();
                continue;
            }
            else if(cnt[curr]==0)
                in.push(curr->left);
            else if(cnt[curr]==1)
                ans.push_back(curr->val);
            else if(cnt[curr]==2)
                in.push(curr->right);
            else in.pop();
            cnt[curr]++;
        }
        
        return ans;
        
    }
};