//Ques: Given a array nums return a vector of all subsets(power set)


void backtracking(vector<int>& nums,vector<int>& s,vector<vector<int> >& ss,int index)
{
        ss.push_back(s);
        for(int i=index; i<nums.size(); i++)
        {
                s.push_back(nums[i]);
                backtracking(nums,s,ss,i+1);
                s.pop_back();

        }
        return;
}

vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> s;
        vector<vector<int> > ss;
        int index=0;
        backtracking(nums,s,ss,index);

        return ss;
}
