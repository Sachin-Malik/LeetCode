class Solution {
public:
bool isPossible(vector<int>& nums) {
        //map to store the frequencies
        unordered_map<int,int> freq;
        for(int i=0; i<nums.size(); i++)
                freq[nums[i]]++;
        unordered_map<int,int> mp;//contains the subsequences endings
        for(int i=0; i<nums.size(); i++)
        {
                //make sure the element is not  used
                if(freq[nums[i]]>0)
                {

                        if(mp[nums[i]-1]>0)
                        {
                                //if there is a subsequence eding with nums-1 attahc to it
                                mp[nums[i]-1]--;
                                mp[nums[i]]++;
                        }
                        else{
                                //if no subsequence then create one
                                if(freq[nums[i]+1]<=0 || freq[nums[i]+2]<=0)
                                        return false; //we can't split
                                freq[nums[i]+1]--;
                                freq[nums[i]+2]--;
                                mp[nums[i]+2]++;
                        }
                        freq[nums[i]]--;
                }
        }
        return true;
}
};
