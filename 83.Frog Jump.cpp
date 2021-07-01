class Solution {
public:
//memo map
map<pair<int,int>,bool> memo;
bool canCross(vector<int>& stones) {

        //starting edge cases
        if(stones[1]!=1)
                return false;
        if(stones.size()==2)
                return true;

        int n=stones.size(),current_pos=stones[1],target=stones[n-1];
        unordered_map<int,int> is_stone;
        for(auto stone:stones)
                is_stone[stone]=1;



        //main_function call
        return recursive(1,1,target,is_stone);


}
bool recursive(int current_pos,int jump,int &target,unordered_map<int,int>&is_stone)
{
        if(current_pos>target)
                return memo[{current_pos,jump}];


        if(memo.find({current_pos,jump})!=memo.end()) {
                cout<<"Cache Hit!!"<<endl;
                return memo[{current_pos,jump}];
        }

        if(jump<=0)
                return false;


        if(current_pos==target) {
                memo[{current_pos,jump}]=true;
                return memo[{current_pos,jump}];
        }

        if(is_stone.find(current_pos)==is_stone.end()) {
                memo[{current_pos,jump}]=false;
                return memo[{current_pos,jump}];
        }


        memo[{current_pos,jump}] = recursive(current_pos+jump,jump,target,is_stone)||
                                   recursive(current_pos+jump+1,jump+1,target,is_stone)||
                                   recursive(current_pos+jump-1,jump-1,target,is_stone);


        return memo[{current_pos,jump}];
}
};
