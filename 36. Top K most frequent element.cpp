///Question :Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest.
// If two words have the same frequency, then the word with the lower alphabetical order comes first.

class cmp
{
public:
    bool operator()(pair<int, string> A, pair<int, string> B)
    {
        if (A.first > B.first)
        {
            return true;
        }
        if (A.first < B.first)
        {
            return false;
        }
        if (A.first == B.first)
        {
            if (A.second > B.second)
                return false;
        }
        return true;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {

        unordered_map<string, int> um;
        vector<string> ans;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for (int i = 0; i < words.size(); i++)
            um[words[i]]++;
        int l = 0;
        for (auto i = um.begin(); i != um.end(); i++)
        {
            pq.push({i->second, i->first});
            if (l > k - 1)
            {
                pq.pop();
            }
            l++;
        }
        while (!pq.empty())
        {

            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};