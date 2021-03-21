

// Given an integer n, return the number of structurally unique BST's
// (binary search trees) which has exactly n nodes of unique values from 1 to n.


class Solution {
public:
int numTrees(int n) {
        vector<int> res(n+1);
        if(n==0)
                return 1;
        if(n==1)
                return 1;
        if(n==2)
                return 2;
        res[0]=1;
        res[1]=1;
        res[2]=2;
        int sum=0;
        for(int i=3; i<=n; i++)
        {
                for(int j=0; j<i; j++)
                {
                        sum=sum+(res[j]*res[i-1-j]);
                }
                res[i]=sum;
                sum=0;
        }
        return res[n];

}
};
