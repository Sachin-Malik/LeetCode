class Solution {
public:
bool check(vector<vector<int> > &dp, int threshold,int assumelength){
        //Her check that assumelength square length matrix have sum how much should be less than equal to threshold
        int minsum=INT_MAX;
        for(int i=0; i<dp.size(); i++) {
                for(int j=0; j<dp[i].size(); j++) {
                        if(i - assumelength>=0 and j - assumelength>=0) {
                                minsum=dp[i][j]- dp[i - assumelength][j] - dp[i][j -assumelength] + dp[i - assumelength][j - assumelength];
                                if(minsum<= threshold) return true;
                        }
                }
        }
        return false;
}
int maxSideLength(vector<vector<int> >& mat, int threshold) {
        int rows=mat.size();
        int cols=mat.at(0).size();
        int min_side=INT_MIN;

        vector<vector<int> > sums(rows+1,vector<int>(cols+1,0));
        for(int i=1; i<sums.size(); i++)
                for(int j=1; j<sums.at(0).size(); j++) {
                        sums[i][j]=mat[i-1][j-1]+sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1];
                        if(mat[i-1][j-1]<=threshold)
                                min_side=1;
                }

        if(min_side==INT_MIN)
                return 0;

        int left=0,right=min(rows,cols);
        while(right>left) {
                int mid=left+(right-left+1)/2;
                if(check(sums,threshold,mid))
                        left=mid;
                else
                        right=mid-1;
        }
        return left;
}
};
