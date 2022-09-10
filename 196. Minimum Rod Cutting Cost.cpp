class Solution {
public:
int dp[101][101];
int util(int i,int j,vector<int>&cuts){
        if(i>j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        int temp=INT_MAX;
        for(int k=i; k<=j; k++) {
                int cost=cuts[j+1]-cuts[i-1]+util(i,k-1,cuts)+util(k+1,j,cuts);
                temp=min(temp,cost);
        }
        return dp[i][j]=temp;
}
int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
        int i=1,j=cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        return util(i,j,cuts);
}
};
