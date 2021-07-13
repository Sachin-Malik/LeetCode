class Solution {
public:

vector<int> circularPermutation(int n, int start) {
        vector<int> ans=recursive(n);
        int index=-1;

        for(int i=0; i<ans.size(); i++)
                if(ans[i]==start)
                {
                        index=i;
                        break;
                }
        reverse(ans.begin(),ans.begin()+index);
        reverse(ans.begin()+index,ans.end());
        reverse(ans.begin(),ans.end());
        return ans;
}
vector<int> recursive(int n)
{
        if(n==1)
                return {0,1};
        vector<int> prev=recursive(n-1);
        for(int i=prev.size()-1; i>=0; i--)
                prev.push_back(prev[i]+pow(2,n-1));

        return prev;
}
};
