class Solution {
public:
vector<int> res;
unordered_map<int,bool> visited;
unordered_map<int,vector<int> > umap;
vector<int> restoreArray(vector<vector<int> >& adjacentPairs) {


        for(auto pair:adjacentPairs) {
                umap[pair[0]].push_back(pair[1]);
                umap[pair[1]].push_back(pair[0]);
        }

        //first start with the node with indegree equal to 1;
        int startNode;
        for(auto ele:umap) {
                if(ele.second.size()==1) {
                        startNode=ele.first;
                }
        }

        //then traverse all not visited nodes ant push them into result vector
        dfs(startNode);
        return res;
}

void dfs(int currentNode){
        if(visited.find(currentNode)!=visited.end())
                return;

        res.push_back(currentNode);
        visited[currentNode]=true;

        for(int i=0; i<umap[currentNode].size(); i++) {
                dfs(umap[currentNode][i]);
        }
}
};
