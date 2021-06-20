class Solution {
public:
int max_profit=INT_MIN;
int maxProfit(vector<int>& prices, int fee) {

        int min_cost=INT_MAX,profit=0,n=prices.size(),index=0;
        int current_profit=0;
        vector<vector<int> > profits(n,vector<int>(2,-1));
        int sell_state=0;
        return find_max_profit(index,prices,fee,0, profits);
}

int find_max_profit(int index,vector<int>&prices,int &fee,int sell_state, vector<vector<int> >& profits)
{
        if(index==prices.size())
                return 0;

        if(profits[index][sell_state]!=-1)
                return profits[index][sell_state];

        if(sell_state==1)
        {
                profits[index][1]=max(prices[index]-fee+find_max_profit(index+1,prices,fee,0, profits),find_max_profit(index+1,prices,fee,1, profits));
                return profits[index][1];
        }
        else
        {
                profits[index][0]=max(-prices[index]+find_max_profit(index+1,prices,fee,1, profits),find_max_profit(index+1,prices,fee,0, profits));
                return profits[index][0];
        }
}
};
