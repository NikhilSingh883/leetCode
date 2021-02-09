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
    vector<TreeNode*> generateBranch(int start,int end){
        vector<TreeNode*> ret;
        if(start>end)
            ret.push_back(0);
        else if(start == end)
            ret.push_back(new TreeNode(start));
        else{
            for(int i=start;i<=end;i++){
                for(TreeNode *l :generateBranch(start,i-1))
                    for(TreeNode* r:generateBranch(i+1,end))
                        ret.push_back(new TreeNode(i,l,r));
            }
        }
        return ret;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generateBranch(1,n);
    }
};