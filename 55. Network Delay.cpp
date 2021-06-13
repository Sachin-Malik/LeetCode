
typedef pair<int,int> pii;
class Solution {
public:
int networkDelayTime(vector<vector<int> >& times, int n, int k) {

        int max_time=INT_MIN;
        vector<pii> nodes[n+1];
        for(int i=0; i<times.size(); i++) {
                nodes[times[i][0]].push_back(make_pair(times[i][1], times[i][2]));
        }


        int infi=INT_MAX;
        vector<int> cost(n+1,infi);
        vector<int> visited(n+1,false);
        cost[k]=0;

        priority_queue<pii,vector<pii>,greater<pii> > pq;
        pq.push({0,k});

        int u,v,w;
        while(pq.size()!=0)
        {
                pii p=pq.top();
                pq.pop();

                u=p.second;
                if(visited[u])
                        continue;
                visited[u]=true;
                for(auto i:nodes[u])
                {
                        v=i.first;
                        w=i.second;
                        if(cost[v]>cost[u]+w)
                                cost[v]=cost[u]+w;
                        pq.push(make_pair(cost[v],v));
                }

        }

        for(int i=1; i<cost.size(); i++)
                max_time=max(max_time,cost[i]);

        if(max_time==INT_MAX)
                return -1;
        return max_time;

}
};
