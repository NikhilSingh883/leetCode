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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p,*k;
        
        p = k = head;
        for(int i=1;i<n;i++) p = p->next;
        
        ListNode* prev;
        while(p->next!=NULL){
            prev = k;
            p= p->next;
            k=k->next;
        }
        
        if(k==head) return head->next;
        prev->next = k->next;    
        return head;
    }
};