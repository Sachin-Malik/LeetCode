class Solution {
public:
int dp[101][201];
bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return memo(s.length()-1,0,0,s);
}
bool memo(int index,int l,int r,string&s){

        if(index==-1) return l==r;

        if(l>r) return false;

        if(dp[index][100+l-r]!=-1) return dp[index][100+l-r];


        if(s[index]=='(')
                return dp[index][100+l-r]=memo(index-1,l+1,r,s);

        if(s[index]==')')
                return dp[index][100+l-r]=memo(index-1,l,r+1,s);

        else
                return dp[index][100+l-r]= memo(index-1,l,r+1,s)||memo(index-1,l+1,r,s)||memo(index-1,l,r,s);
}
};
