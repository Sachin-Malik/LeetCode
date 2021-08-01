class Solution {
public:
bool increasingTriplet(vector<int>& nums) {

        int n = nums.size();
        if(n<3) return false;   // base case

        int min1 = INT_MAX; // first min
        int min2 = INT_MAX; // second min
        for(auto &t : nums)
        {
                if(t <= min1) min1 = t; // update first min
                else if(t<= min2) min2 = t; // update second min
                else return true; // current number is greater than
                                  // second min and so a triplet found
        }

        return false;   // no triplet found
}
};
