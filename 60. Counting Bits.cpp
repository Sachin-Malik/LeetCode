class Solution {
public:
vector<int> countBits(int n) {
        if(n==0)
                return {0};
        if(n==1)
                return {0,1};
        if(n==2)
                return {0,1,1};

        vector<int> res(n+1,0);
        res[1]=1,res[2]=1;
        int last_two=2;
        for(int i=3; i<=n; i++)
        {
                if(i==2*last_two)
                {
                        res[i]=1;
                        last_two=i;
                }
                else
                        res[i]=res[i-last_two]+1;

        }
        return res;
}
};
