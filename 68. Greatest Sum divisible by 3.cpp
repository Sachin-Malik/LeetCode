class Solution {
public:
int maxSumDivThree(vector<int>& nums) {

        if(nums.size()<2)
                return !nums[0]%3 ? nums[0]:0;

        int s=nums.size(),index=0,sum=0;
        vector<int> dp(s+1,-1),sums(s+1,0);
        sums[s-1]=nums[s-1];
        for(int i=s-2; i>=0; i--)
                sums[i]=sums[i+1]+nums[i];

        return memo(index,sum,nums,dp,sums);

}
int memo(int index,int sum,vector<int>&nums,vector<int>&dp,vector<int>&sums)
{
        if(index==nums.size())
                return sum;


        if(dp[index]!=-1&&sum+sums[index]<=dp[index])
                return dp[index];

        int a=memo(index+1,sum+nums[index],nums,dp,sums);
        int b=memo(index+1,sum,nums,dp,sums);

        if(a%3!=0) a=0;
        if(b%3!=0) b=0;

        dp[index]=max(dp[index],max(a,b));
        return dp[index];
}
};
