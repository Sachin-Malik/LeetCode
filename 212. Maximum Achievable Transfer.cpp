class Solution
{
public:
    int maxFullfiledRequests = 0;
    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        vector<int> net(n, 0);
        helper(0, 0, requests, net);
        return maxFullfiledRequests;
    }

    void helper(int index, int fullfiled, vector<vector<int>> &req, vector<int> &net)
    {
        if (index == req.size())
        {
            for (int i = 0; i < net.size(); i++)
            {
                if (net[i] != 0)
                    return;
            }
            maxFullfiledRequests = max(fullfiled, maxFullfiledRequests);
            return;
        }

        // fullfill this request
        net[req[index][0]]--;
        net[req[index][1]]++;
        helper(index + 1, fullfiled + 1, req, net);
        net[req[index][1]]--;
        net[req[index][0]]++;

        // not fullfill
        helper(index + 1, fullfiled, req, net);
        return;
    }
};