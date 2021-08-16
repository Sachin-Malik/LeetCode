class Solution {
public:
int dp[5001][2002];
int numberOfArithmeticSlices(vector<int>& nums) {

        memset(dp,-1,sizeof(dp));
        int n=nums.size();
        if(n<=2)
                return 0;

        int ans=0;
        for(int i=0; i<n-2; i++) {
                int diff=nums[i+1]-nums[i]+1000;
                ans+=memo(i+2,diff,nums);
        }
        return ans;
}


int memo(int index,int diff,vector<int>&nums){

        if(index==nums.size())
                return 0;

        if(dp[index][diff]!=-1)
                return dp[index][diff];

        if(nums[index]-nums[index-1]!=diff-1000)
                return 0;

        return dp[index][diff]=1+memo(index+1,diff,nums);

}
};
