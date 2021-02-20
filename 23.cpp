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
class Solution {
public:   
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merge = NULL;
        ListNode* root = NULL;
        
        while(true){
            int idx = -1;
            int minVal = INT_MAX;
            
            for(int i=0;i<lists.size();i++){
                if(!lists[i]) continue;
                
                if(lists[i]->val < minVal){
                    minVal = lists[i]->val;
                    idx = i;
                }
            }
            
            if(idx == -1) break;
            
            if(root == NULL){
                merge = root = lists[idx];
            }
            else {
                merge->next = lists[idx];
                merge = merge->next;
            }
            
            lists[idx] = lists[idx]->next;
        }
        
        return root;
    }
};