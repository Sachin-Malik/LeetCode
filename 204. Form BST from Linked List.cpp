// Without using any extra space, just from recursion

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        ListNode* start=head;
        return formTree(start,nullptr);
    }
    
    TreeNode* formTree(ListNode* start, ListNode*end){
        if(start==end) return nullptr;
        ListNode* slow = start;
        ListNode* fast = start;
        while(fast!=end&&fast->next!=end){
            fast=fast->next->next;
            slow=slow->next;
        }
        TreeNode * root=new TreeNode(slow->val);
        root->left=formTree(start,slow);
        root->right=formTree(slow->next,end);
        return root;
    }
};
















