class Solution {
public:
vector<int> avoidFlood(vector<int>& rains) {

        unordered_map<int,int> lake_filled;
        int dry_days=0,n=rains.size();
        vector<int> res(n,100057);
        set<int> q;

        for(int i=0; i<rains.size(); i++) {
                if(rains[i]==0) {
                        dry_days++;
                        q.insert(i);
                }else {
                        res[i]=-1;
                        if(lake_filled.find(rains[i])==lake_filled.end()) {
                                lake_filled[rains[i]]=i;
                        }
                        else{
                                if(dry_days<=0)
                                        return {};

                                auto index=q.upper_bound(lake_filled[rains[i]]);
                                if(index==q.end())
                                        return {};
                                int val=*index;
                                q.erase(index);

                                res[val]=rains[i];
                                lake_filled[rains[i]]=i;

                        }
                }
        }
        return res;
}

};
