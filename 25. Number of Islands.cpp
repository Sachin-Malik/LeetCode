class Solution {
public:
int numIslands(vector<vector<char> >& grid) {
        int counter=0;
        int rows=grid.size();
        if(rows!=0)
        {
                int cols=grid.at(0).size();
                for(int i=0; i<rows; i++)
                {
                        for(int j=0; j<cols; j++)
                        {

                                if(grid[i][j]=='1')
                                {
                                        calculateIslands(grid,i,j,rows,cols);
                                        counter++;
                                }

                        }
                }
        }
        return counter;
}
void calculateIslands(vector<vector<char> > &grid,int i,int j,int &rows,int&cols)
{

        if(i<0||i>=rows||j<0||j>=cols)
                return;
        if(grid[i][j]=='1')
        {
                grid[i][j]='2';
                calculateIslands(grid,i-1,j,rows,cols);
                calculateIslands(grid,i+1,j,rows,cols);
                calculateIslands(grid,i,j-1,rows,cols);
                calculateIslands(grid,i,j+1,rows,cols);
        }
}
};
