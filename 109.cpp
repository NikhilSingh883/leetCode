/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    
    ListNode* head;
        
    int size(){
        int h =0;
        ListNode *ptr = head;
        
        while(ptr!=NULL){
            ptr=ptr->next;
            h++;
        }
        
        return h;
    }
    public:
    TreeNode * convert(int l,int r){
        if(l>r) return NULL;
        
        int mid = (l+r)/2;
        
        TreeNode* left = convert(l,mid-1);
        
        TreeNode* root = new TreeNode(head->val);
        root->left = left;
        
        head = head->next;
        
        root->right = convert(mid+1,r);
        
        return root;
    }
        
    TreeNode* sortedListToBST(ListNode* h) {
        head = h;
        
        int r = size() - 1;
        
        return convert(0,r);
    }
};