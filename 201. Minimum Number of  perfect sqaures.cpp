class Solution {
public:
    int dp[10001];
    int numSquares(int n) {
        vector<int> squares;
        for(int i=1;i<=n;i++){
            if(i*i>n) break;
            squares.push_back(i*i);
        }
        sort(squares.begin(),squares.end(),greater<int>());
        memset(dp,-1,sizeof(dp));
        return memo(n,squares);
    }

    int memo(int target,vector<int>&squares){
       
      if(target==0) return 0;
      if(target<0) return 1e8;

      if(dp[target]!=-1) return dp[target];
      
      int temp=INT_MAX;
      for(int i=0;i<squares.size();i++){
        temp=min(1+memo(target-squares[i],squares),temp);
      }
      return dp[target]=temp;
    }
};