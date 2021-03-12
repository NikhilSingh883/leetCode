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
    ListNode* rotateRight(ListNode* head, int k) {
        int n =0;
        
        
        ListNode* temp = head;
        ListNode* end;
        
        while(temp){
            if(temp->next==NULL) end = temp;
            temp = temp->next;
            n++;
        }
        
        if(n==0) return NULL;
        k = k%n;
        if(k==0) return head;
        
        int m = n - k;
        temp = head;
        ListNode* prev;
        
        while(m--){
            prev = temp;
            temp = temp->next;
        }
        end->next = head;

        head = temp;
        prev->next = NULL;
        
        
        return head;
        
    }
};