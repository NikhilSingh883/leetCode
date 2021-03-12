class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before = new ListNode(0);                  // creating new list to store node less than x
        ListNode* after = new ListNode(0);                     //  creating new list to store node greater than x
        ListNode* ptr1=before;                                       // pointer pointing to head of before list
        ListNode* ptr2=after;                                          // pointer pointing to head of after list
        ListNode* ptr=head;                                           // pointer pointing to head of original list
        while(ptr!=NULL)
        {
            if(ptr->val < x)                                                         // if less than x
            {
                ptr1->next=ptr;                                                // adding the node to before list
                ptr1=ptr1->next;                                              // increamenting the pointer of before list for future elements
            }
            else
            {
                ptr2->next=ptr;                                                 // adding node to after list
                ptr2=ptr2->next;                                               // increamenting the pointer of after list for future elements
            }
            ptr=ptr->next;                                                      // incrementing the pointer of original list
        }  
        ptr2->next=NULL;                                                 // adding to NULL in end of after list
        ptr1->next=after->next;                                      
        return before->next;                                            
    }
};