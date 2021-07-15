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

        if(head==NULL||k==0)
                return head;
        int count=1;
        ListNode* current=head;
        while(current->next!=NULL) {
                current=current->next;
                count++;
        }
        k%=count;
        k=count-k-1;

        current->next=head;
        current=current->next;
        while(k--)
                current=current->next;

        ListNode* kthNode=current->next;
        current->next=NULL;
        return kthNode;

}
};
