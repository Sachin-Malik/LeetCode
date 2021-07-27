class Solution {
public:
vector<int> nextGreaterElements(vector<int>& nums) {

        vector<int> res(nums.size(),-1);
        int intial=nums.size();
        for(int i=0; i<intial; i++)
                nums.push_back(nums[i]);

        stack<pair<int,int> > st;

        st.push({nums[0],0});
        for(int i=1; i<nums.size(); i++) {
                while(!st.empty()&&st.top().first<nums[i]) {
                        auto [val,index]=st.top();
                        st.pop();
                        res[index]=nums[i%intial];
                }
                st.push({nums[i],i%intial});
        }
        return res;
}
};
