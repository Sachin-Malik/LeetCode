class Solution {
public:
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> umap;
        for(int i=0; i<nums2.size(); i++)
                umap[nums2[i]]=i;

        vector<int> greater(nums2.size()+1,-1);
        stack<pair<int,int> > st;
        nums2.push_back(INT_MIN);
        for(int i=0; i<nums2.size(); i++)
        {
                if(i==0) {
                        st.push({nums2[i],i});
                        continue;
                }
                while(!st.empty()&&st.top().first<nums2[i])
                {
                        int ans_index=st.top().second;
                        greater[ans_index]=nums2[i];
                        st.pop();
                }
                st.push({nums2[i],i});
        }
        while(st.size()!=0)
        {
                greater[st.top().second]=-1;
                st.pop();
        }
        vector<int> res;
        for(int i=0; i<nums1.size(); i++)
                res.push_back(greater[umap[nums1[i]]]);


        return res;
}
};
