class UndergroundSystem
{
public:
    unordered_map<int, pair<string, int>> umap;
    map<pair<string, string>, pair<double, int>> map;
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        umap[id] = make_pair(stationName, t);
        return;
    }

    void checkOut(int id, string stationName, int t)
    {
        auto [startStation, boardingTime] = umap[id];
        int timeTaken = t - boardingTime;
        auto [avg, trips] = map[make_pair(startStation, stationName)];

        double newAvg = (avg * trips + timeTaken) / double(trips + 1);
        map[make_pair(startStation, stationName)] = make_pair(newAvg, trips + 1);
        return;
    }

    double getAverageTime(string startStation, string endStation)
    {
        return map[make_pair(startStation, endStation)].first;
    }
};
