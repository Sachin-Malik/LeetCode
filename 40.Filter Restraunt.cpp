class cmp {
public:
bool operator()(pair<int,int> p1,pair<int,int> p2)
{
        if(p1.second>p2.second)
                return false;
        else if(p1.second<p2.second)
                return true;
        else{
                if(p1.first>p2.first)
                        return false;
                return true;
        }
}
};
class Solution {
public:
vector<int> filterRestaurants(vector<vector<int> >& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int>res;
        priority_queue<pair<int,int>,vector<pair<int,int> >,cmp> pq;
        for(int i=0; i<restaurants.size(); i++)
        {
                if(veganFriendly==0||restaurants[i][2]==veganFriendly)
                        if(restaurants[i][3]<=maxPrice&&restaurants[i][4]<=maxDistance)
                                pq.push(make_pair(restaurants[i][0],restaurants[i][1]));

        }
        while(pq.size()) {
                res.push_back(pq.top().first);
                pq.pop();
        }

        return res;

}
};
