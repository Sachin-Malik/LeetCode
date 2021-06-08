class compare {
public:
bool operator()(pair<int,ListNode*> const &p1,pair<int,ListNode*> const &p2)
{
        if(p1.first<=p2.first)
                return false;
        return true;
}
};
class Solution {
public:
ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(0);
        ListNode* res=dummy;
        int n=lists.size();


        if(n==0)
                return NULL;
        else if(n==1)
                return lists[0];

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*> >,compare> pq;

        for(int i=0; i<n; i++)
                if(lists[i]!=NULL)
                        pq.push({lists[i]->val,lists[i]});

        while(pq.size()!=0)
        {
                pair<int,ListNode*> t=pq.top();
                pq.pop();
                res->next=new ListNode(t.first);
                res=res->next;
                ListNode* next=t.second->next;
                if(next!=NULL)
                        pq.push({next->val,next});
        }
        return dummy->next;
}
};
