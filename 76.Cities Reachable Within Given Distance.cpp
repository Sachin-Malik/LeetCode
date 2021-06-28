class Solution {
public:
vector<pair<int,int> > graph[101];
int findTheCity(int n, vector<vector<int> >& edges, int distanceThreshold) {

        for(int i=0; i<edges.size(); i++) {
                graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
                graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }

        int city,min_val=INT_MAX,connected_cities;

        for(int i=0; i<n; i++)
        {
                connected_cities=dijkstra(i,distanceThreshold,n);
                if(connected_cities<=min_val)
                {
                        min_val=connected_cities;
                        city=i;
                }
        }

        return city;
}

int dijkstra(int starting_node,int & distanceThreshold,int &n)
{
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        vector<int> dist(n+1,INT_MAX);
        int current_node,current_distance;
        pq.push({0,starting_node});

        while(pq.size()!=0)
        {
                int curr=pq.top().second;
                int curr_d=pq.top().first;
                pq.pop();

                for(auto edge : graph[curr])
                {
                        if(curr_d+edge.second < dist[edge.first])
                        {
                                dist[edge.first]=curr_d+edge.second;
                                pq.push({dist[edge.first],edge.first});
                        }
                }
        }
        int count=0;
        for(int i=0; i<n; i++)
                if(i!=starting_node)
                        if(dist[i]<=distanceThreshold)
                                count++;

        return count;
}
};
