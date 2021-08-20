class Solution {
public:
int BIG_NUMBER = -100000;
vector<vector<int> > offsets={{1,0},{0,1},{-1,0},{0,-1}};
int latestDayToCross(int row, int col, vector<vector<int> >& cells) {
        vector<vector<int> > grid(row,vector<int>(col,0));

        for(int i=0; i<cells.size(); i++)
                grid[cells[i][0]-1][cells[i][1]-1]=i+1;
        vector<vector<int> > temp;
        int left=0,right=cells.size(),mid,ans=INT_MIN;
        while(left<=right) {

                mid=(left+right)/2;
                bool can_cross=false;
                for(int i=0; i<col; i++) {
                        temp=grid;
                        can_cross=travel_grid(i,mid,temp);
                        if(can_cross)
                                break;
                }
                if(can_cross) {
                        ans=max(ans,mid);
                        left=mid+1;
                }
                else
                        right=mid-1;
        }
        return ans;
}
bool travel_grid(int col,int &mid,vector<vector<int> >&grid){
        queue<pair<int,int> > q;
        int rows=grid.size(),cols=grid.at(0).size();
        q.push({0,col});

        while(!q.empty())
        {
                int l=q.size();
                for(int k=0; k<l; k++)
                {
                        auto [x,y]=q.front();
                        q.pop();

                        if(grid[x][y]<=mid)
                                continue;

                        if(x==rows-1&&grid[x][y]>mid)
                                return true;

                        grid[x][y]=BIG_NUMBER;
                        for(int m=0; m<4; m++) {

                                int X=x-offsets[m][0];
                                int Y=y-offsets[m][1];

                                if(X<0||Y<0||X>=rows||Y>=cols)
                                        continue;

                                q.push({X,Y});
                        }
                }
        }
        return false;
}
};
