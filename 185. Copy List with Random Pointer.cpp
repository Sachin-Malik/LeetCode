class Solution {
public:
Node* copyRandomList(Node* head) {

        Node* itr=head;
        Node* dummyHead=new Node(-1);
        Node* temp=dummyHead;

        int index=0;
        while(itr!=nullptr) {
                temp->next=new Node(itr->val);
                itr=itr->next;
                temp=temp->next;
        }

        unordered_map<Node*,Node*> oldToNew;
        itr=head;
        temp=dummyHead->next;
        while(itr!=nullptr) {
                oldToNew[itr]=temp;
                itr=itr->next;
                temp=temp->next;
        }

        temp=dummyHead->next;
        itr=head;
        while(temp!=nullptr) {
                temp->random=oldToNew[itr->random];
                temp=temp->next;
                itr=itr->next;
        }
        return dummyHead->next;
}
};
