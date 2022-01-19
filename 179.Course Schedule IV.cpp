class Solution {
public:
int dp[101][101];
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int> >& prerequisites, vector<vector<int> >& queries) {

        memset(dp,-1,sizeof(dp));
        vector<vector<int> > graph(numCourses);
        vector<bool> res(queries.size(),false);

        for(auto &pre:prerequisites)
                graph[pre[0]].push_back(pre[1]);

        for(int i=0; i<queries.size(); i++) {
                res[i]=dfs(queries[i][0],queries[i][1],graph);
        }
        return res;
}

bool dfs(int currentNode,int target,vector<vector<int> >&graph){

        if(currentNode==target)
                return true;

        if(dp[currentNode][target]!=-1)
                return dp[currentNode][target];

        bool temp=false;
        for(int i=0; i<graph[currentNode].size(); i++) {
                temp=temp|dfs(graph[currentNode][i],target,graph);
        }

        return dp[currentNode][target]=temp;
}
};
