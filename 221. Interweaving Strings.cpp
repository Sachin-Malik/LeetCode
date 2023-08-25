class Solution
{
public:
    int dp[101][101];
    bool isInterleave(string s1, string s2, string s3)
    {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();

        if (l1 + l2 != l3)
            return false;
        memset(dp, -1, sizeof(dp));
        return helper(0, 0, s1, s2, s3);
    }

    bool helper(int p1, int p2, string &s1, string &s2, string &s3)
    {
        if (p1 == s1.size() && p2 == s2.size())
            return true;
        if (dp[p1][p2] != -1)
            return dp[p1][p2];

        bool temp = false;
        // can be taken from 1st string
        if (p1 < s1.size() && s1[p1] == s3[p1 + p2])
        {
            temp = temp || helper(p1 + 1, p2, s1, s2, s3);
        }

        // can be taken from 2nd string
        if (p2 < s2.size() && s2[p2] == s3[p1 + p2])
        {
            temp = temp || helper(p1, p2 + 1, s1, s2, s3);
        }
        return dp[p1][p2] = temp;
    }
};