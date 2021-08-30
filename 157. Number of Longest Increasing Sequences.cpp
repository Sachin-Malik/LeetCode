class Solution {
public:
int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1), c(n, 1);

        for(int i=1; i<n; i++)
        {
                for(int j=0; j<i; j++)
                {
                        if(nums[i]>nums[j])
                        {
                                if(dp[j]+1 > dp[i])//same subsequence
                                {
                                        dp[i]=dp[j]+1;
                                        c[i]=c[j];
                                }
                                else if(dp[j]+1==dp[i])//different subsequence
                                {
                                        c[i]+=c[j];
                                }

                        }
                }

        }

        int max_val = INT_MIN;
        for(int i=0; i<n; i++) {
                max_val=max(max_val,dp[i]);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
                if(dp[i]==max_val)
                        count += c[i];
        }

        return count;
}
};
