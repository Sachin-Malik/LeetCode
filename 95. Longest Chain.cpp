class Solution {
public:
static bool mysort(const vector<int>&v1,const vector<int>&v2)
{
        if(v1[0]<v2[0])
                return true;
        if(v1[0]>v2[0])
                return false;
        if(v1[1]<=v2[1])
                return true;
        return false;
}
int findLongestChain(vector<vector<int> >& pairs) {
        sort(pairs.begin(),pairs.end(),mysort);
        int count=1,max_val=pairs[0][1];

        for(int i=1; i<pairs.size(); i++)
        {
                if(pairs[i][0]>max_val)
                {
                        max_val=pairs[i][1];
                        count++;
                }
                else
                        max_val=min(max_val,pairs[i][1]);
        }
        return count;
}
};
