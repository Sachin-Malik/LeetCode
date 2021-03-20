// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0?
//Find all unique triplets in the array which gives the sum of zero.

// Notice that the solution set must not contain duplicate triplets.


class Solution {
public:
vector<vector<int> > threeSum(vector<int>& nums) {
        set<vector<int> > s;
        vector<vector<int> > res;
        vector<int> v;
        int n = nums.size();
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++) {
                int num = nums[i];
                int start = i+1;
                int end = n - 1;

                while(start < end) {
                        int a = nums[start];
                        int b = nums[end];

                        if(a+b == -num) {
                                v.clear();
                                v.push_back(num);
                                v.push_back(a);
                                v.push_back(b);

                                s.insert(v);
                                start++;
                                end--;
                        }

                        else if(a+ b < -num) {
                                start++;
                        }
                        else{
                                end--;
                        }
                }
        }

        set<vector<int> >:: iterator it;

        for(it = s.begin(); it!= s.end(); it++) {
                res.push_back(*it);
        }

        return res;
}
};
