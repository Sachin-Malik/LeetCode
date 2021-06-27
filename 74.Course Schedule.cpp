
class Solution {
public:
bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<vector<int> > graph(numCourses);


        for(int i=0; i<prerequisites.size(); i++)
                graph[prerequisites[i][0]].push_back(prerequisites[i][1]);

        for(int i=0; i<numCourses; i++)
                if(visited[i]==0)
                        if(is_cyclic(i,visited,graph))
                                return false;
        return true;
}

bool is_cyclic(int current_node,vector<int> &visited,vector<vector<int> >&graph)
{
        if(visited[current_node]==2)
                return true;

        visited[current_node]=2;
        for(int i=0; i<graph[current_node].size(); i++) {
                if(visited[graph[current_node][i]]!=1)
                        if(is_cyclic(graph[current_node][i],visited,graph))
                                return true;
        }
        visited[current_node]=1;
        return false;
}
};
