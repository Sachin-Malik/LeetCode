class Solution {
public:
int edge_len=0;
vector<bool> visited;
bool makesquare(vector<int>& matchsticks) {
        int total_length=0,n=matchsticks.size();
        for(auto&match:matchsticks)
                total_length+=match;

        if(total_length%4)
                return false;

        edge_len=total_length/4;
        int current_len=0;
        visited.resize(n);
        fill(visited.begin(),visited.end(),false);
        return backtrack(0,0,current_len,matchsticks);

}
bool backtrack(int index,int count,int current_len,vector<int>&matchsticks){
        if(count==3) {
                return true;
        }

        if(current_len==edge_len)
                return backtrack(0,count+1,0,matchsticks);

        for(int i=index; i<matchsticks.size(); i++) {

                if(visited[i]||matchsticks[i]+current_len>edge_len)
                        continue;

                visited[i]=true;
                if(backtrack(i,count,current_len+matchsticks[i],matchsticks)) return true;
                visited[i]=false;
        }
        return false;
}
};
