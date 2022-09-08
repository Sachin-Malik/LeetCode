class Solution {
public:
vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> hash(n+1);
        vector<int> dp(n+1,1);

        for(int i=1; i<n; i++) {
                for(int j=0; j<i; j++) {
                        if(nums[i]%nums[j]==0) {
                                if(dp[i]<1+dp[j]) {
                                        dp[i]=1+dp[j];
                                        hash[i]=j;
                                }
                        }
                }
        }

        int maxVal=-1,indexOfMaxVal=-1;
        for(int i=0; i<n; i++) {
                if(dp[i]>maxVal) {
                        maxVal=dp[i];
                        indexOfMaxVal=i;
                }
        }

        vector<int> res;
        maxVal--;
        res.push_back(nums[indexOfMaxVal]);
        while(maxVal--) {
                indexOfMaxVal=hash[indexOfMaxVal];
                res.push_back(nums[indexOfMaxVal]);
        }
        reverse(res.begin(),res.end());
        return res;
}
};
