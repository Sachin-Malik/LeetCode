class Solution {
public:
vector<vector<int> > offsets={{1,0},{0,1},{-1,0},{0,-1}};
int countSubIslands(vector<vector<int> >& grid1, vector<vector<int> >& grid2) {

        int subIslands=0;
        for(int i=0; i<grid2.size(); i++)
                for(int j=0; j<grid2.at(0).size(); j++)
                        if(grid2[i][j]==1&&grid1[i][j]==1)
                                if(mark_islands(i,j,grid1,grid2))
                                        subIslands++;
        return subIslands;
}

bool mark_islands(int i,int j,vector<vector<int> >&g1,vector<vector<int> >&g2){

        if(i<0||j<0||i>=g1.size()||j>=g1.at(0).size())
                return true;

        if(g2[i][j]==0)
                return true;

        if(g2[i][j]==1&&g1[i][j]!=1)
                return false;

        g1[i][j]=0;
        g2[i][j]=0;

        bool res=true;
        for(int m=0; m<4; m++)
                res=res & mark_islands(i-offsets[m][0],j-offsets[m][1],g1,g2);
        return res;
}
};
