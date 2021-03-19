class Solution {
public:
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
ListNode *ans = new ListNode(0), *t1=l1, *t2=l2;
ListNode *anshead=ans;
int carry=0;

    while(t1||t2){
        if(t1){
            carry+= t1->val;
            t1 = t1->next;
        }
        if(t2){
            carry+= t2->val;
            t2 = t2->next;
        }
        ans->val = carry%10;
        carry /= 10;
        if(t1||t2||carry){
            ans->next = new ListNode(carry);
            ans = ans->next;
        }
    }
    return anshead;
}
};
