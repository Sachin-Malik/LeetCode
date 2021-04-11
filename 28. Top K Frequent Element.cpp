class Solution {
public:
vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        priority_queue<pair<int,int> > pq;
        int n=nums.size();

        for(int i=0; i<n; i++)
                umap[nums[i]]++;

        for(auto itr:umap)
                pq.push(make_pair(itr.second,itr.first));

        vector<int> res;
        int counter=0;
        pair<int,int> temp;
        while(counter<k) {
                counter++;
                temp =pq.top();
                res.push_back(temp.second);
                pq.pop();
        }
        sort(res.begin(),res.end());
        return res;

}
};
