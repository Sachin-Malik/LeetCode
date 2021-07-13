class Solution {
public:

vector<vector<int> > offsets={{0,1},{0,-1},{1,0},{-1,0}};
int maxDistance(vector<vector<int> >& grid) {
        int max_distance=-1;

        queue<pair<int,int> > q;
        vector<vector<int> > res(grid.size(),vector<int>(grid.at(0).size(),-1));
        for(int i=0; i<grid.size(); i++)
                for(int j=0; j<grid.at(0).size(); j++)
                        if(grid[i][j]==1) {
                                q.push({i,j});
                                res[i][j]=0;
                        }

        int current_distance=1;
        while(!q.empty()) {
                int l=q.size();
                for(int m=0; m<l; m++)
                {
                        auto [i,j]=q.front();
                        q.pop();
                        for(int k=0; k<4; k++)
                        {
                                int X=i-offsets[k][0];
                                int Y=j-offsets[k][1];

                                if(X<0||Y<0||X>=grid.size()||Y>=grid.at(0).size()||res[X][Y]!=-1)
                                        continue;

                                res[X][Y]=current_distance;
                                max_distance=max(max_distance,res[X][Y]);
                                q.push({X,Y});
                        }

                }
                current_distance++;

        }
        return max_distance;
}
};
