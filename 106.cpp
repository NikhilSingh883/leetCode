class Solution {
    unordered_map<int, int> nodeIndices;
    int postOrderIndex = 0;
public:

    
    TreeNode *buildBinaryTree(vector<int> &inorder, vector<int> &postorder, int start, int end){
        if(start > end) return nullptr;
        
        TreeNode *root = new TreeNode(postorder.at(postOrderIndex--));
        
        int index   = nodeIndices.at(root->val);
        root->right = buildBinaryTree(inorder, postorder, index + 1, end);
        root->left  = buildBinaryTree(inorder, postorder, start, index - 1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < postorder.size(); i++)
            nodeIndices[inorder[i]] = i;
        
        postOrderIndex = postorder.size() - 1;
        return buildBinaryTree(inorder, postorder, 0, inorder.size() - 1);
    }
};