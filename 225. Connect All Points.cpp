class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int c = 0;
        vector<vector<pair<int, int>>> graph(points.size());
        for (int i = 0; i < points.size(); i++)
            for (int j = 0; j < points.size(); j++)
                if (i != j)
                    graph[i].push_back({getDistance(points[i], points[j]), j});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int startNode = 0;
        vector<bool> visited(points.size(), false);
        pq.push({0, 0});
        while (pq.size())
        {
            auto [lastDistance, currentNode] = pq.top();
            pq.pop();
            if (visited[currentNode])
                continue;
            visited[currentNode] = true;

            c += lastDistance;
            for (int i = 0; i < graph[currentNode].size(); i++)
                pq.push({graph[currentNode][i].first, graph[currentNode][i].second});
        }
        return c;
    }

    int getDistance(vector<int> &p1, vector<int> &p2)
    {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};