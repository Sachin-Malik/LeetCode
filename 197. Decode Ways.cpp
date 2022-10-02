class Solution {
public:
     int dp[101][2];
    int memo(int index, bool canUsePrevious, string&s){
        if(index==s.size()) return 1;

        if(dp[index][canUsePrevious]!=-1) return dp[index][canUsePrevious];

        //are we allowed to use previous
        if(canUsePrevious){
           int temp=0;

           //can only start new if s[index]!='0'
           if(s[index]!='0')
           temp+=memo(index+1,true,s);

           //pairing it with previous
           if(s[index-1]=='1'||(s[index-1]=='2'&&s[index]-'0'<7))
                temp+=memo(index+1,false,s);
           return dp[index][canUsePrevious]=temp;

        }else{ // we are not allowed
            int temp=0;
           if(s[index]=='0') return 0;
           temp = memo(index+1,true,s);
            return dp[index][canUsePrevious]=temp;
        }
        
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        if(s[0]=='0') return 0;
        return memo(0,false,s); 
    }
};