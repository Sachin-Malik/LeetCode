class Solution {
public:
int dp[101][101];
int minFallingPathSum(vector<vector<int> >& matrix) {

        for(int i=0; i<101; i++)
                for(int j=0; j<101; j++)
                        dp[i][j]=-1;

        int row=matrix.size(),col=matrix.at(0).size(),res=INT_MAX;

        for(int j=0; j<col; j++)
                res=min(memo(0,j,matrix),res);

        return res;
}
int memo(int i,int j,vector<vector<int> >&matrix)
{

        if(i==matrix.size())
                return 0;

        if(dp[i][j]!=-1)
                return dp[i][j];

        if(j-1>=0&&j+1<matrix.at(0).size())
                return dp[i][j]=min({memo(i+1,j,matrix),memo(i+1,j+1,matrix),memo(i+1,j-1,matrix)})+matrix[i][j];

        else if(j-1>=0)
                return dp[i][j]=min({memo(i+1,j,matrix),memo(i+1,j-1,matrix)})+matrix[i][j];

        else
                return dp[i][j]=min({memo(i+1,j,matrix),memo(i+1,j+1,matrix)})+matrix[i][j];
}
};
