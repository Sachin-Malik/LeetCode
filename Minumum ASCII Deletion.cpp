class Solution {
public:

int minimumDeleteSum(string s1, string s2) {
        int s1_len=s1.length(),s2_len=s2.length();
        vector<vector<int> > dp(s1_len+1,vector<int>(s2_len+1,0));
        int s1_score=0,s2_score=0;

        //get sum of ASCII values for both strings.
        for(int i=0; i<s1_len; i++)
                s1_score+=(int)s1[i];
        for(int j=0; j<s2_len; j++)
                s2_score+=(int)s2[j];

        //to get common subsequence.
        //instead of maintaining the length just maintain Sum of ASCII values of longest commont subsequence.
        for(int i=1; i<dp.size(); i++)
                for(int j=1; j<dp.at(0).size(); j++)
                        if(s1[i-1]==s2[j-1])
                                dp[i][j]=dp[i-1][j-1]+int(s1[i-1]);
                        else
                                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);

        //score of s1 +score of s2 - 2(longest common subsequence with highest ASCII score)
        return s1_score+s2_score-(2*dp[s1_len][s2_len]);
}

};
