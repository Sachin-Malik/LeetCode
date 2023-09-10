class Solution {
    public:
        long long dp[501][501];
    long long MOD=1e9+7;

    int countOrders(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, n)%MOD;
    }

    long long helper(long long i, long long j, long long n) {

        if(i>=n && j>=n) return 1;

        if(dp[i][j] !=-1) return dp[i][j];

        long long temp=0;

        //if i can be increased
        if(i<n) {
            long long result=((n-i)*(helper(i+1, j, n)%MOD))%MOD;
            temp+=result;
            temp%=MOD;
        }

        //if j can be increase
        if(j<i) {
            long long result=((i-j)*helper(i, j+1, n)%MOD)%MOD;
            temp+=result;
            temp%=MOD;
        }

        return dp[i][j]=temp%MOD;
    }
}

;