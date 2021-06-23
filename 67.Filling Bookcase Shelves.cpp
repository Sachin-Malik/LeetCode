//My First Recustion+Memoization Solution (kinda proud on this one).
//Note: In this solution there is no actual use of var "level" but it make it easy to understand for begineers like me.

typedef vector<vector<int> > matrix;
class Solution {
public:
int minHeightShelves(vector<vector<int> >& books, int sw) {
        matrix dp(1001,vector<int>(10002,-1));
        int index=0,level=0,height=0,cw=0;
        bool first=true;
        return memo(level,index,cw,height,first,books,sw,dp);
}

int memo(int level,int index,int cw,int height,bool first,matrix& books, int &sw,matrix&dp)
{

        if(index==books.size())
                return height;

        if(dp[index][cw]!=-1)
                return dp[index][cw];

        //if there are no books in this row just but this one.
        if(first==true)
        {
                height=books[index][1];
                dp[index][cw]=memo(level,index+1,cw+books[index][0],height,false,books,sw,dp);
                return dp[index][cw];
        }
        //if this book can be places on this row then we have two options
        else if(cw+books[index][0]<=sw)
        {
                dp[index][cw]=min(memo(level,index+1,cw+books[index][0],max(height,books[index][1]),false,books,sw,dp),
                                  memo(level+1,index,0,0,true,books,sw,dp)+height);
                return dp[index][cw];
        }

        //else you have to put this on next row
        else
        {
                dp[index][cw]=memo(level+1,index,0,0,true,books,sw,dp)+height;
                return dp[index][cw];
        }
}
};
