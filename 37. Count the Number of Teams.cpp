class Solution
{
public:
    int numTeams(vector<int> &nums)
    {
        int ll = 0, lg = 0, rl = 0, rg = 0;
        int res = 0;
        int n = rating.size();
        for (int i = 1; i < n - 1; i++)
        {
            ll = 0, lg = 0, rl = 0, rg = 0;

            for (int j = i - 1; j >= 0; j--)
            {
                if (rating[j] > rating[i])
                    lg++;

                else
                    ll++;
            }

            for (int j = i + 1; j < n; j++)
            {
                if (rating[j] > rating[i])
                    rg++;
                else
                    rl++;
            }
            res += ll * rg + lg * rl;
        }

        return res;
    }
};