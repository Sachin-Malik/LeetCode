class Solution {
public:
vector<int> singleNumber(vector<int>& nums) {
        int res=0;
        for(auto num:nums)
                res=res^num;


        int counter=0;
        counter=(res)&(~(res-1));
        vector<int> even;
        for(auto num:nums)
        {
                if(num&counter)
                        even.push_back(num);
        }

        int temp=0;
        for(auto i:even)
                temp=temp^i;

        return {temp,temp^res};

}
};
