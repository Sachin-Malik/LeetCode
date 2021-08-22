class Solution {
public:
void reorderList(ListNode* head) {

        if(head==NULL||head->next==NULL||head->next->next==NULL)
                return;

        stack<ListNode*> st;
        int sz=0;
        ListNode*ptr=head;
        while(ptr!=NULL) {
                sz++;
                st.push(ptr);
                ptr=ptr->next;
        }
        ListNode*curr=head;
        for(int i=0; i<sz/2; i++) {
                ListNode* element=st.top();
                st.pop();
                element->next=curr->next;
                curr->next=element;
                curr=curr->next->next;
        }
        curr->next=NULL;
}
};
