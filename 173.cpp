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
class BSTIterator {
public:
    stack<TreeNode*> S;
    BSTIterator(TreeNode* root) {
        while(root){
            S.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* ans = S.top();
        int re = S.top()->val;
        S.pop();
        ans = ans->right;
        while(ans!=NULL){
            S.push(ans);
            ans = ans->left;
        }
        
        return re;
    }
    
    bool hasNext() {
        return !S.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */