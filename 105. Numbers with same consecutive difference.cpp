class Solution {
public:
vector<int> res;
vector<int> numsSameConsecDiff(int n, int k) {
        int current_num;
        for(int i=1; i<=9; i++)
        {
                current_num=i;
                backtrack(current_num,1,n,k);

        }
        return res;
}
void backtrack(int current_num,int count,int &limit,int&k)
{

        if(count==limit)
        {
                res.push_back(current_num);
                return;
        }


        for(int i=0; i<=9; i++)
                if(abs((current_num%10)-i)==k)
                {
                        current_num*=10;
                        current_num+=i;
                        backtrack(current_num,count+1,limit,k);
                        current_num/=10;
                }
}
};
