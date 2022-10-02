bool isCycle(int currentNode,vector<int>&visited,vector<int>&currentDFS,vector<vector<int>>&graph){
    
    if(visited[currentNode]==true){
        return currentDFS[currentNode];
    }
    visited[currentNode]=true;
    currentDFS[currentNode]=true;
    for(int i=0;i<graph[currentNode].size();i++){
        if(isCycle(graph[currentNode][i],visited,currentDFS,graph)) return true;
    }
    currentDFS[currentNode]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> visited(n+1,false),currentDFS(n+1,false);
    vector<vector<int>> graph(n+1);
    for(auto edge:edges){
        graph[edge.first].push_back(edge.second);
    }
    for(int i=1;i<=n;i++){
        if(visited[i]==false)
        if(isCycle(i,visited,currentDFS,graph)) return true;
    }
    return false;
}