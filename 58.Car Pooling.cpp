class Solution {
public:
bool carPooling(vector<vector<int> >& trips, int capacity) {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        int n=trips.size();
        int current_distance=0;
        sort(trips.begin(),trips.end(),sortcol);
        for(auto trip:trips)
        {
                current_distance=trip[1];
                while(pq.size()!=0&&pq.top().first<=current_distance)
                {
                        capacity+=pq.top().second;
                        pq.pop();
                }
                if(capacity<trip[0])
                        return false;
                else
                {
                        pq.push({trip[2],trip[0]});
                        capacity-=trip[0];
                }
        }
        return true;
}
static bool sortcol(vector<int> &v1,vector<int> &v2)
{
        if(v1[1]<=v2[1])
                return true;
        return false;

}
};
