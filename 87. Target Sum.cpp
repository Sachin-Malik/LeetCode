class Solution {
public:
int dp[21][2002];
int findTargetSumWays(vector<int>& nums, int target) {
        for(int i=0; i<21; i++)
                for(int j=0; j<2002; j++)
                        dp[i][j]=-1;
        return memo(0,target,0,nums);
}
int memo(int index,int target,int current_sum,vector<int>&nums)
{
        if(index==nums.size())
                if(current_sum==target)
                        return 1;
                else return 0;

        if(dp[index][1000+current_sum]!=-1)
                return dp[index][1000+current_sum];

        return dp[index][1000+current_sum]=memo(index+1,target,current_sum+nums[index],nums)+
                                            memo(index+1,target,current_sum-nums[index],nums);
}
};
