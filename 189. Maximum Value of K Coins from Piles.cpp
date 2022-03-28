class Solution {
public:
int dp[1001][2001];
int maxValueOfCoins(vector<vector<int> >& piles, int k) {

        memset(dp,-1,sizeof(dp));
        vector<vector<int> > sums;
        for(int i=0; i<piles.size(); i++) {
                sums.push_back({0});
                int prev=0;
                for(int j=0; j<piles[i].size(); j++) {
                        sums[i].push_back(prev+piles[i][j]);
                        prev+=piles[i][j];
                }
        }
        return memo(0,k,sums);
}
int memo(int index, int k, vector<vector<int> >&sums){

        if(index==sums.size()) {
                if(k==0) return 0;
                else return -100000;
        }

        if(k==0)
                return 0;

        if(k<0)
                return -100000;


        if(dp[index][k]!=-1)
                return dp[index][k];

        int temp=0;
        int l=sums[index].size()-1;
        for(int i=0; i<=min(k,l); i++)
                temp=max(temp,sums[index][i]+memo(index+1,k-i,sums));

        return dp[index][k]=temp;
}
};
