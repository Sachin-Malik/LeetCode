class Solution {
public:
void dfs(int i, vector<vector<int> > &stones, vector<int> &vis){
        int j,u=stones[i][0], v=stones[i][1];
        vis[i]=1;
        for(j=0; j<stones.size(); j++) {
                if(vis[j]==0 && (stones[j][0]==u || stones[j][1]==v)) {
                        dfs(j,stones,vis);
                }
        }
}
int removeStones(vector<vector<int> >& stones) {
        int i,n=stones.size(),grp=0;
        vector<int> vis(n,0);
        for(i=0; i<n; i++) {
                if(vis[i]==0) {
                        grp++;
                        dfs(i,stones,vis);
                }
        }
        return n-grp;
}
};
