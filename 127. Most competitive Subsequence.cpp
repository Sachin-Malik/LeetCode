class Solution {
public:
vector<int> mostCompetitive(vector<int>& nums, int k) {
        if(k==nums.size())
                return nums;
        vector<int> res;

        priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
        for(int i=0; i<=nums.size()-k; i++)
                pq.push({nums[i],i});

        int current_index=-1,count=k,pointer=nums.size()-k;
        while(count--) {
                while(pq.top().second<current_index)
                        pq.pop();
                res.push_back(pq.top().first);
                current_index=pq.top().second;
                pq.pop();
                pointer++;
                if(pointer<nums.size())
                        pq.push({nums[pointer],pointer});
        }
        return res;
}
};
