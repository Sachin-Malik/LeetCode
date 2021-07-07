class Solution {
public:
int dp[501][502];
int maxSumAfterPartitioning(vector < int > & arr, int k) {
        memset(dp,-1,sizeof(dp));
        return memo(0,1,INT_MIN,k,arr);
}
int memo(int index, int counter, int c_max, int k, vector <int> & nums) {

        if (index==nums.size())
                return 0;

        if(dp[index][counter]!=-1)
                return dp[index][counter];

        int new_max = max(nums[index],c_max);

        if (counter==k)
                return dp[index][counter]=(k*new_max)+memo(index+1,1,0,k,nums);
        else
                return dp[index][counter]=max((counter*new_max)+memo(index+1,1,0,k,nums),
                                              memo(index+1,counter+1,new_max,k,nums));
}
};
