
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy=new ListNode(0,head);
       
        ListNode* ptr1=dummy;
        ListNode *ptr2=dummy;
        
        for(int i=0;i<n;i++)
            ptr1=ptr1->next;
        
        while(ptr1->next!=NULL)
        {
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        
        ptr2->next=ptr2->next->next;
       
        return dummy->next;
    }
};