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



// ONE KINDA IMPORTANT THING IN ALL THESE EASY LINKED LIST TYPE QUESTION IS THAT
//CREATE A NEW DUMMY NODE WHICH REALLY HELPS IN CORNER CASES.
class Solution {
public:
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp=new ListNode(0);
        ListNode* dummy=temp;
        ListNode* ptr1=l1;
        ListNode* ptr2=l2;

        while(ptr1!=NULL&&ptr2!=NULL)
        {
                if(ptr1->val<=ptr2->val)
                {
                        dummy->next=ptr2;
                        ptr2=ptr2->next;
                        dummy=dummy->next;
                }
                else{
                        dummy->next=ptr1;
                        ptr1=ptr1->next;
                        dummy=dummy->next;
                }
        }
        while(ptr1!=NULL)
        {
                dummy->next=ptr1;
                ptr1=ptr1->next;
                dummy=dummy->next;
        }
        while(ptr2!=NULL)
        {
                dummy->next=ptr2;
                ptr2=ptr2->next;
                dummy=dummy->next;
        }
        return temp->next;

}
};
