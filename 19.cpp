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
        ListNode* p1=head,*p2=nullptr;
        while(p1)
        {
            if(n<=0)
            {
                if(p2) p2=p2->next;  // if n<=0 start moving p2, this will move p2
                else p2=head;       // until p1!=null hence it will stop before nth node from end.
            }
            p1=p1->next;
            n--;
        }
        
        if(p2) p2->next=p2->next->next;
        else head=head->next;  // if node to be deleted is the 1st node
        return head;
    }
};