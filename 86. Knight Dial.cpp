class Solution {
public:
int dp[5001][4][3];
int MOD=1000000007;
vector<vector<int> > directions ={{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
int knightDialer(int n) {

        for(int i=0; i<5001; i++)
                for(int j=0; j<4; j++)
                        for(int z=0; z<3; z++)
                                dp[i][j][z]=-1;

        int res=0;
        for(int i=0; i<4; i++)
                for(int j=0; j<3; j++)
                        if(i==3&&(j==0||j==2))
                                continue;
                        else
                                res=res%MOD+memo(i,j,n-1)%MOD;

        return res%MOD;

}
int memo(int i,int j,int n)
{
        if(i>=4||i<0||j>=3||j<0)
                return 0;
        if(i==3&&(j==0||j==2))
                return 0;

        if(n==0)
                return 1;

        if(dp[n][i][j]!=-1)
                return dp[n][i][j];

        int res=0;
        for(int p=0; p<directions.size(); p++)
                res=res%MOD+memo(i-directions[p][0],j-directions[p][1],n-1)%MOD;
        return dp[n][i][j]=res;
}
};
