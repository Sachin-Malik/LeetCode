class Solution
{
public:
    void dfs(string &airport, unordered_map<string, vector<string>> &graph, vector<string> &itinerary)
    {
        while (!graph[airport].empty())
        {
            string next = graph[airport].back();
            graph[airport].pop_back();
            dfs(next, graph, itinerary);
        }
        itinerary.push_back(airport);
    }
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        unordered_map<string, vector<string>> graph;

        for (auto &ticket : tickets)
        {
            graph[ticket[0]].push_back(ticket[1]);
        }
        for (auto &temp : graph)
        {
            sort(temp.second.rbegin(), temp.second.rend());
        }

        vector<string> itinerary;
        string jfk = "JFK";
        dfs(jfk, graph, itinerary);

        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};