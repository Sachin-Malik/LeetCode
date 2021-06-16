//Ques No. 825

class Solution {
public:
int numFriendRequests(vector<int>& ages) {


        unordered_map<int,int> umap;
        for(auto age:ages)
                umap[age]++;

        vector<pair<int,int> > vtr;
        for(auto i:umap)
                vtr.push_back({i.first,i.second});

        int n=vtr.size(),friend_requests=0;
        for(int i=0; i<n; i++)
        {
                if((double)vtr[i].first> (double)(vtr[i].first/2)+7)
                        friend_requests+=vtr[i].second*(vtr[i].second-1);
                for(int j=0; j<n; j++)
                {
                        if(i!=j)
                        {
                                if((vtr[j].first>100&&vtr[i].first<100)||vtr[j].first>vtr[i].first||vtr[j].first<= (vtr[i].first/2)+7)
                                        continue;
                                else
                                        friend_requests+=(vtr[i].second*vtr[j].second);
                        }
                }
        }
        return friend_requests;
}
};
