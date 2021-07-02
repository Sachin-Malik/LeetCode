class Solution {
public:
int MOD=1000000007;
int numRollsToTarget(int d, int f, int target) {
        if(d*f<target) return 0;
        if(d*f==target) return 1;
        vector<vector<int> > dp(d+1,vector<int>(target+1,-1));
        int current_sum=0;
        return memo(current_sum,d,target,f,dp);
}
int memo(int current_sum,int dice,int &target,int &f,  vector<vector<int> >&dp)
{

        if(current_sum>target||dice<0)
                return 0;

        if(dp[dice][current_sum]!=-1)
                return dp[dice][current_sum]%MOD;

        if(current_sum==target&&dice==0)
        {
                dp[dice][current_sum]=1;
                return dp[dice][current_sum]%MOD;
        };

        dp[dice][current_sum]=0;
        for(int i=1; i<=f; i++)
        {
                dp[dice][current_sum]=dp[dice][current_sum]%MOD+memo(current_sum+i,dice-1,target,f,dp)%MOD;
                dp[dice][current_sum]%MOD;
        }
        return dp[dice][current_sum]%MOD;
}
};
