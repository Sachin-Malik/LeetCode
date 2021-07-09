class Solution {
public:
long long dp[501][501];
int MOD=1000000007;
int countOrders(int n) {
        memset(dp,-1,sizeof(dp));
        return (int)memo(0,0,n);
}
int memo(long long p,long long d,long long n)
{

        if(p==n&&d==n)
                return 1;

        if(p<n&&d<n&&dp[p][d]!=-1)
                return dp[p][d];

        if(p==n&&d!=n)
                return dp[p][d]=(((p-d)%MOD)*(memo(p,d+1,n)%MOD))%MOD;

        if(p==d&&p!=n)
                return dp[p][d]=(((n-p)%MOD)*(memo(p+1,d,n)%MOD))%MOD;

        else
                return dp[p][d]=( (((n-p)%MOD)*(memo(p+1,d,n)%MOD)%MOD) + ((((p-d)%MOD)*(memo(p,d+1,n)))%MOD)%MOD)%MOD;
}
};
