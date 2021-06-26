class Solution {
public:
vector<vector<string> >res;
vector<vector<string> > solveNQueens(int n) {
        vector<string> board;
        string intial="";
        for(int i=0; i<n; i++)
                intial+=char(46);
        for(int i=0; i<n; i++)
                board.push_back(intial);

        int queens=n,row=0,col=0;
        place_n_queens(queens,row,col,n,board);
        return res;

}
void place_n_queens(int queens,int row,int col,int &n,vector<string> &board)
{
        if(queens==0) {
                res.push_back(board);
                return;
        }
        if(col==board.size())
        {
                row++;
                col=0;
        }
        if(row==board.size())
                return;

        if(can_placed_at(row,col,n,board)==true) {
                board[row][col]='Q';
                place_n_queens(queens-1,row,col+1,n,board);
                board[row][col]='.';

        }
        place_n_queens(queens,row,col+1,n,board);
}

bool can_placed_at(int i,int j,int &n,vector<string> &board)
{

        //check for all 8 directions
        int x=i,y=j;
        while(x>=0)
        {
                if(board[x][y]=='Q')
                        return false;
                x--;
        }
        x=i,y=j;
        while(y>=0)
        {
                if(board[x][y]=='Q')
                        return false;
                y--;
        }
        x=i,y=j;
        while(y<n)
        {
                if(board[x][y]=='Q')
                        return false;
                y++;
        }
        x=i,y=j;
        while(x>=0&&y>=0)
        {
                if(board[x][y]=='Q')
                        return false;
                x--,y--;
        }
        x=i,y=j;
        while(x>=0&&y<n)
        {
                if(board[x][y]=='Q')
                        return false;
                x--,y++;
        }
        x=i,y=j;
        while(x<n&&y>=0)
        {
                if(board[x][y]=='Q')
                        return false;
                x++,y--;
        }
        return true;
}
};
