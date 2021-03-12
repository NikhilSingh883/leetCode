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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev = new ListNode(-101);
        ListNode* re = prev;
        
        if(!head) return head;
        
        while(temp){
            if(temp->val != prev->val){
                prev->next = temp;
                prev = prev->next;
            }
            
            temp=temp->next;
        }
        prev->next = NULL;
        return re->next;
    }
};