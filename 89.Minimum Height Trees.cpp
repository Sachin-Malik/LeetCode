class Solution {
public:
vector<int> findMinHeightTrees(int n, vector<vector<int> >& edges) {
        if(n==1)
                return {0};
        vector<int> graph[n+1];
        vector<int> in_degree(n,0);

        for(auto edge:edges)
        {
                graph[edge[0]].push_back(edge[1]);
                graph[edge[1]].push_back(edge[0]);
                in_degree[edge[1]]++;
                in_degree[edge[0]]++;

        }

        queue<int> q;
        for(int i=0; i<n; i++)
                if(in_degree[i]==1)
                        q.push(i);

        while(n>2)
        {
                int leaf_nodes=q.size();
                n-=leaf_nodes;
                for(int i=0; i<leaf_nodes; i++)
                {
                        int current_node=q.front();
                        q.pop();
                        for(auto node:graph[current_node])
                        {
                                in_degree[node]--;
                                if(in_degree[node]==1)
                                        q.push(node);
                        }
                }
        }
        vector<int> res;
        while(!q.empty())
        {
                res.push_back(q.front());
                q.pop();
        }
        return res;

}
};
