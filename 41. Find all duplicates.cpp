class Solution {
public:
vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
                int index = abs(nums[i])-1; // using abs becoz that value can become negetive
                nums[index] *= -1;
                if(nums[index]>0)
                        ans.push_back(abs(nums[i])); // using abs becoz that value can be negetive
        }
        return ans;
}
};
