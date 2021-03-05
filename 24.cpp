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
    ListNode* swapPairs(ListNode* h) {
        
        int k = 0;
        ListNode *prev;
        ListNode* head = h;
        
        while(head!=NULL){
            if(k%2){
                int temp = head->val;
                head->val = prev->val;
                prev->val = temp;
            }
            prev = head;
            k++;
            head = head->next;

        }
        
        return h;
    }
};