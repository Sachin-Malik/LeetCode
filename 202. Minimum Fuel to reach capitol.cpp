class Solution {
public:
    long long int result=0;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> graph(roads.size()+1);
        for(auto road:roads){
            graph[road[0]].push_back(road[1]);
            graph[road[1]].push_back(road[0]);
        }

        vector<int> visited(roads.size()+1,0);
        helper(0,seats,graph,visited);
        return result;
    }

    int helper(int currentNode,int &seats,vector<vector<int>>&graph,vector<int>&visited){

       if(visited[currentNode]!=0) return 0;
       visited[currentNode]=1;

       int peopleComing=0;
       int totalPeople=0;
       for(int i=0;i<graph[currentNode].size();i++){
           peopleComing=helper(graph[currentNode][i],seats,graph,visited);
           result+=(peopleComing/seats);
           if(peopleComing%seats!=0) result+=1;
           totalPeople+=peopleComing;
       }
       return totalPeople+1;  
    }
};