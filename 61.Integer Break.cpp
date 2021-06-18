class Solution {
public:
int integerBreak(int n) {

        vector<int> multiplications(n+1,0);
        if(n==2)
                return 1;
        if(n==3)
                return 2;
        multiplications[0]=0,multiplications[1]=1,multiplications[2]=2,multiplications[3]=3;
        for(int i=3; i<=n; i++)
                for(int j=1; j<i; j++)
                        multiplications[i]=max(multiplications[i],(multiplications[j]*multiplications[(i-j)]));
        return multiplications[n];
}
};

