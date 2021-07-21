class Solution {
public:
int dp[101][101];
vector<int> findBall(vector<vector<int> >& grid) {
        memset(dp,-1,sizeof(dp));
        vector<int> ans(grid.at(0).size());
        for(int i=0; i<grid.at(0).size(); i++) {
                ans[i]=memo(0,i,grid);
        }
        return ans;
}
int memo(int i,int j,vector<vector<int> >&grid){


        int new_x=i+1;
        int new_y=j+grid[i][j];

        if(new_y<0||new_y==grid.at(0).size()) {
                // cout<<"Stucked on Wall"<<endl;
                return -1;
        }

        if(grid[i][new_y]!=grid[i][j]) {
                // cout<<"Stucked in V Section"<<endl;
                return -1;
        }
        if(new_x==grid.size()) {
                // cout<<"Reached the End"<<endl;
                return new_y;
        }
        if(dp[i][j]!=-1) {
                // cout<<"Cache Hit!!"<<endl;
                return dp[i][j];
        }

        return dp[i][j]=memo(new_x,new_y,grid);

}
};
