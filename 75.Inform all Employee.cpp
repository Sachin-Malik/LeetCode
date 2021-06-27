class Solution {
public:
int max_time=INT_MIN;
int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int start=headID,time=0;
        vector<vector<int> > graph(n);
        vector<bool> visited(n);

        for(int i=0; i<manager.size(); i++)
                if(manager[i]!=-1)
                        graph[manager[i]].push_back(i);

        inform_emplyees(headID,visited,graph,time,informTime);
        return max_time;
}
void inform_emplyees(int current_node,vector<bool>&visited,vector<vector<int> >&graph,int time,vector<int>&informTime)
{
        if(!visited[current_node])
        {
                max_time=max(max_time,time);
                visited[current_node]=true;
                for(int i=0; i<graph[current_node].size(); i++)
                        if(!visited[graph[current_node][i]])
                                inform_emplyees(graph[current_node][i],visited,graph,
                                                time+informTime[current_node],informTime);
        }
}
};
