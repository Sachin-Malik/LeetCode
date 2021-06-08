class Solution {
public:
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int> > pq;
        int n=nums.size(),maxVal=INT_MIN;
        vector<int> res;

        for(int i=0; i<k; i++)
                pq.push({nums[i],i});

        auto top=pq.top();
        res.push_back(top.first);
        for(int i=k; i<n; i++)
        {
                pq.push({nums[i],i});
                while(pq.top().second<=i-k)
                        pq.pop();
                res.push_back(pq.top().first);
        }
        return res;
}
};
