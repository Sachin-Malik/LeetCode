class Solution {
public:
bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        vector<int> mins(n,INT_MAX);
        stack<int> st;

        mins[0]=nums[0];
        for(int i=1; i<nums.size(); i++) {
                mins[i]=min(mins[i-1],nums[i]);
        }

        for(int i=n-1; i>=0; i--) {
                if(nums[i]>mins[i]) {
                        while(!st.empty()&&st.top()<=mins[i]) st.pop();
                        if(!st.empty()&&st.top()<nums[i])
                                return true;
                        st.push(nums[i]);
                }
        }
        return false;
}
};
