#define ppi pair<pair<int,int>,int>
class compare {
public:
bool operator()(ppi&p1,ppi&p2){
        if(p1.second<p2.second)
                return false;
        if(p1.second>p2.second)
                return true;

        return p1.first.first>p2.first.first;
}
};

class Solution {
public:
int nthUglyNumber(int n) {
        vector<int> res;
        priority_queue<ppi,vector<ppi>,compare> pq;

        if(n==1)
                return 1;

        res.push_back(1);
        pq.push({{2,0},2});
        pq.push({{3,0},3});
        pq.push({{5,0},5});

        n--;
        while(n>0) {
                int val=pq.top().second;
                int prime=pq.top().first.first;
                int index=pq.top().first.second;
                pq.pop();

                if(res.back()!=val) {
                        n--;
                        res.push_back(val);
                }

                val=prime*res[index];
                pq.push({{prime,index+1},val});
        }

        return res[res.size()-1];
}
};
