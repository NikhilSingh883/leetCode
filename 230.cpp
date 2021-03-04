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
    void inOrder(TreeNode *A, int &B, int &ans){
        if(A == NULL) return;
        inOrder(A->left, B, ans);

        B--;
        if(B==0){
            ans = A->val;
            return;
        }

        inOrder(A->right, B, ans);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        inOrder(root,k,ans);
        return ans;
    }
};