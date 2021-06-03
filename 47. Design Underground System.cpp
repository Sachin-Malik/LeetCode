class UndergroundSystem {
public:
map<int,pair<string,int> > inTransit;
map<pair<string,string>,pair<int,int> > stations;
UndergroundSystem() {

}

void checkIn(int id, string stationName, int t) {
        inTransit[id]={stationName,t};
}

void checkOut(int id, string stationName, int t) {

        int timeTaken,boardedAt;
        string stationBoarded=inTransit[id].first;
        boardedAt=inTransit[id].second;
        timeTaken=t-boardedAt;
        pair<int,int> p =stations[{stationBoarded,stationName}];
        stations[{stationBoarded,stationName}]={p.first+timeTaken,p.second+1};
        inTransit.erase(id);
}

double getAverageTime(string startStation, string endStation) {
        double ans;
        pair<int,int> time=stations[{startStation,endStation}];
        cout<<time.first<<" "<<time.second<<endl;
        ans=(double)time.first/time.second;
        return ans;
}
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
