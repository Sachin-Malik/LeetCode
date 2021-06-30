class Solution {
public:

double maxProbability(int n, vector<vector<int> >& edges, vector<double>& succProb, int start, int end) {
        //build graph
        vector<vector<pair<double,double> > > graph(n);
        for(int i=0; i<edges.size(); i++) {
                graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
                graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }

        double max_prob=dijkstra(start,end,n,graph);
        if(max_prob==INT_MIN)
                return 0;
        return max_prob;
        return 0;
}


double dijkstra(int &start,int&target,int &n,vector<vector<pair<double,double> > > graph)
{
        priority_queue<pair<double,int> > pq;
        vector<double> probability(n,INT_MIN);
        probability[start]=0;
        pq.push({1,start});

        while(pq.size()!=0)
        {
                double curr=pq.top().second;
                double curr_d=pq.top().first;
                pq.pop();
                for(int i=0; i<graph[curr].size(); i++)
                {
                        if((graph[curr][i].second)*(curr_d)>probability[graph[curr][i].first])
                        {
                                probability[graph[curr][i].first]=(graph[curr][i].second)*(curr_d);
                                pq.push({probability[graph[curr][i].first],graph[curr][i].first});
                        }
                }
        }

        return probability[target];
}
};
