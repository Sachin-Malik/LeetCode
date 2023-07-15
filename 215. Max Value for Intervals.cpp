class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        priority_queue<int> finishedEvents;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> inQueue;
        sort(events.begin(), events.end());
        int maxVal = INT_MIN;
        for (int i = 0; i < events.size(); i++)
        {
            while (inQueue.size() && inQueue.top().first < events[i][0])
            {
                finishedEvents.push(inQueue.top().second);
                inQueue.pop();
            }
            inQueue.push({events[i][1], events[i][2]});
            int temp = 0;
            if (finishedEvents.size())
            {
                temp = finishedEvents.top();
            }
            temp += events[i][2];
            maxVal = max(maxVal, temp);
        }
        return maxVal;
    }
};