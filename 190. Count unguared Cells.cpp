class Solution {
public:

// This is mapping of direction to next coordinates
unordered_map<char,pair<int,int> > directionOffsets;
int countUnguarded(int m, int n, vector<vector<int> >& guards, vector<vector<int> >& walls) {
        long long totalCells =0;
        directionOffsets['U']={0,1};
        directionOffsets['D']={0,-1};
        directionOffsets['L']={-1,0};
        directionOffsets['R']={1,0};

        /*------------------------------------------------------------------------------------
         |     1.  'u' is for unexplored and 'e' is for explored                               \
         \     2.   We will just count the number of 'u' in the end to find un protected cells |
           -------------------------------------------------------------------------------------*/
        vector<vector<char> > grid(m,vector<char>(n,'u'));
        for(auto &guard:guards) {
                grid[guard[0]][guard[1]]='g';
        }

        for(auto &wall:walls) {
                grid[wall[0]][wall[1]]='w';
        }

        for(int i=0; i<m; i++) {
                for(int j=0; j<n; j++) {
                        if(grid[i][j]=='g') {
                                //this encountered guard can move in all direction.
                                exploreGrid(grid,i-1,j,'L');
                                exploreGrid(grid,i+1,j,'R');
                                exploreGrid(grid,i,j+1,'U');
                                exploreGrid(grid,i,j-1,'D');
                        }
                }
        }

        for(int i=0; i<m; i++)
                for(int j=0; j<n; j++)
                        if(grid[i][j]=='u')
                                totalCells++;

        return totalCells;
}

/*-------------------------------------------------------------------------------------------------
|            1. After taking the first step guard can only continue in that particular direction  |
|               until a wall or another guard is encountered                                      |
|            2.That direction is being passed from grid loop                                      |
   -------------------------------------------------------------------------------------------------*/

void exploreGrid(vector<vector<char> > &grid,int x,int y, char direction){
        if(x>=grid.size()||x<0||y>=grid.at(0).size()||y<0||grid[x][y]=='w'||grid[x][y]=='g')
                return;

        grid[x][y]='e';
        auto p=directionOffsets[direction];
        x=x+p.first;
        y=y+p.second;
        exploreGrid(grid,x,y,direction);
        return;

}
};
