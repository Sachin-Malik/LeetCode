class Solution {
public:
    int maxLengthCycle = -1;
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n);

        for(int i=0;i<edges.size();i++)
            if(edges[i]!=-1)
                graph[i].push_back(edges[i]);

        // -1 is start value            
        vector<int> visited(n,-1);

       
        for(int i=0;i<n;i++){
            if(visited[i]==-1)
                dfs(i,0,visited,graph);
        }
        return maxLengthCycle;
    }

    void dfs(int currentNode, int edgesTravelled, vector<int> &visited, vector<vector<int>>& graph){
        if(visited[currentNode]!=-1 && visited[currentNode]!=10011212){
            //Here if the node has neither startValue or endValue 
            //that means it is a part of current Cycle.
            int currentLength = edgesTravelled-visited[currentNode];
            maxLengthCycle=max(maxLengthCycle,currentLength);
            return;
        }
        visited[currentNode]=edgesTravelled;
        for(int i=0;i<graph[currentNode].size();i++){
            dfs(graph[currentNode][i],edgesTravelled+1,visited,graph);
        }
        //some endValue
        visited[currentNode]=100011212;
        return;
    }
};