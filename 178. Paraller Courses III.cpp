class Solution {
public:
vector<bool> visited;
unordered_map<int,int> mp;
int minimumTime(int n, vector<vector<int> >& relations, vector<int>& time) {
        vector<int> indegree(n+1,0);
        visited.resize(n+1,false);
        vector<vector<int> > graph(n+1);
        for(auto &rel:relations) {
                graph[rel[0]].push_back(rel[1]);
                indegree[rel[1]]++;
        }

        int temp=0;
        for(int i=1; i<=n; i++)
                if(indegree[i]==0)
                        temp=max(temp,dfs(i,graph,time));
        return temp;
}
int dfs(int currentNode,vector<vector<int> >&graph,vector<int>&time){

        if(mp.find(currentNode)!=mp.end())
                return mp[currentNode];

        int temp=time[currentNode-1];
        int res=0;
        for(int i=0; i<graph[currentNode].size(); i++) {
                res=max(res,dfs(graph[currentNode][i],graph,time));
        }
        return mp[currentNode]=temp+res;
}
};
