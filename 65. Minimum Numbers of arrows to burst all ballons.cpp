class Solution {
public:
int findMinArrowShots(vector<vector<int> >& points) {
        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        int n=points.size();
        for(int i=0; i<n; i++)
                pq.push({points[i][0],points[i][1]});
        int arrows_shot=1,max=pq.top().second;
        pq.pop();
        while(pq.size()!=0)
        {
                if(pq.top().first>max)
                {
                        max=pq.top().second;
                        arrows_shot++;
                }
                max=min(max,pq.top().second);
                pq.pop();
        }
        return arrows_shot;
}
};
