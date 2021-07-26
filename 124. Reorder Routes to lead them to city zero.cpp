class Solution {
public:
map<pair<int,int>, int> mp;
int c=0;
void bfs(vector<vector<int> > vec, vector<int> &vis, int idx)
{
        queue<int> q;
        q.push(idx);
        while(!q.empty())
        {
                auto x = q.front();
                q.pop();
                vis[x]=1;
                for(int i=0; i<vec[x].size(); i++)
                {
                        if(!vis[vec[x][i]])
                        {
                                q.push(vec[x][i]);
                                if(mp[{x,vec[x][i]}]) c++;
                        }
                }
        }
}
int minReorder(int n, vector<vector<int> >& connections)
{
        vector<vector<int> > vec(n,vector<int>());
        for(auto x: connections)
        {
                vec[x[0]].push_back(x[1]);
                vec[x[1]].push_back(x[0]);
                mp[{x[0],x[1]}]=1;
        }
        vector<int> vis(n, 0);
        bfs(vec, vis, 0);
        return c;
}
};
