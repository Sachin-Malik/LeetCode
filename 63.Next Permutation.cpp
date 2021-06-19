class Solution {
public:
void nextPermutation(vector<int>& nums) {
        int n=nums.size(),current_max=nums[n-1],flag=0,index=0;
        priority_queue<pair<int,int> >pq;
        pq.push({nums[n-1],n-1});
        for(int i=n-2; i>=0; i--)
        {
                if(nums[i]>=current_max) {
                        current_max=nums[i];
                        pq.push({nums[i],i});
                }
                else {

                        flag=1;
                        while(pq.size()!=0&&pq.top().first>nums[i])
                        {
                                index=pq.top().second;
                                pq.pop();
                        }

                        swap(nums[i],nums[index]);
                        sort(nums.begin()+i+1,nums.end());
                        break;
                }
        }
        if(flag!=1)
                sort(nums.begin(),nums.end());
}

};
