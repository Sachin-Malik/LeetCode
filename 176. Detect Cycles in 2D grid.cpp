class Solution {
public:
vector<vector<int> > visited;
vector<vector<int> > offsets={{1,0},{0,1},{0,-1},{-1,0}};
bool containsCycle(vector<vector<char> >& grid) {
        visited=grid;
        for(int i=0; i<grid.size(); i++)
                fill(grid[i].begin(),grid[i].end(),0);

        vector<vector<int> > visited(grid.size(),vector<int>(grid.at(0).size(),0));
        for(int i=0; i<grid.size(); i++)
                for(int j=0; j<grid.at(0).size(); j++) {
                        if(visited[i][j]==0&&hasCycle(i,j,1,grid[i][j],grid)) {
                                return true;
                        }
                }
        return false;
}


bool hasCycle(int i,int j,int currentSteps,char &target,vector<vector<char> >&grid){

        int rows=grid.size(),cols=grid.at(0).size();
        if(i<0||i>=rows||j<0||j>=cols||grid[i][j]!=target)
                return false;

        if(visited[i][j]!=0) {
                return currentSteps-visited[i][j]>=3;
        }

        visited[i][j]=currentSteps;
        bool isCyclic=false;

        for(int k=0; k<offsets.size(); k++)
                isCyclic=isCyclic|hasCycle(i-offsets[k][0],j-offsets[k][1],currentSteps+1,target,grid);

        return isCyclic;

}
};
