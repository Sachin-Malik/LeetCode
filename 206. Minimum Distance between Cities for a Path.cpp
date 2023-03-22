class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n+1);
        vector<bool> visited(n+1,false);
        
        for(auto &road:roads){
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }
        
        traverseGraph(1,visited,graph);

        int minDistance=INT_MAX;
        for(auto &road:roads){
            if(visited[road[0]]&&visited[road[1]]) 
                minDistance=min(minDistance,road[2]);
        }
        return minDistance;
    }

    void traverseGraph(int currentNode,vector<bool>&visited, vector<vector<int>>&graph){

        if(visited[currentNode]) return;
        visited[currentNode]=true;

        for(int i=0;i<graph[currentNode].size();i++){
            traverseGraph(graph[currentNode][i],visited,graph);
        }
        return;
    }
};