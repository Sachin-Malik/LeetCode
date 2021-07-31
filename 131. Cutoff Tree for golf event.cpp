class Solution {
public:
int sx=0,sy=0;
vector<vector<int> > offsets={{1,0},{0,1},{-1,0},{0,-1}};
int cutOffTree(vector<vector<int> >& forest) {

        if(forest[0][0]==0)
                return -1;

        vector<int> tree_heights;
        for(int i=0; i<forest.size(); i++) {
                for(int j=0; j<forest.at(0).size(); j++) {
                        if(forest[i][j]!=1&&forest[i][j]!=0)
                                tree_heights.push_back(forest[i][j]);
                }
        }

        sort(tree_heights.begin(),tree_heights.end());
        vector<vector<int> > temp;

        int total_steps=0,target;
        for(int i=0; i<tree_heights.size(); i++) {
                target=tree_heights[i];
                temp=forest;
                int h=find_tree(sx,sy,target,temp);
                if(h==-1) {
                        return -1;
                }
                total_steps+=h;
                forest[sx][sy]=1;
        }
        return total_steps;
}

int find_tree(int xi,int yi,int target,vector<vector<int> >&temp){

        if(temp[xi][yi]==target) {
                sx=xi;
                sy=yi;
                return 0;
        }

        queue<pair<int,int> > q;
        q.push({xi,yi});

        int current_steps=1;

        while(!q.empty()) {
                int l=q.size();
                for(int z=0; z<l; z++) {
                        auto[i,j]=q.front();
                        q.pop();

                        for(int m=0; m<4; m++) {

                                int x=i-offsets[m][0];
                                int y=j-offsets[m][1];

                                if(x<0||y<0||x>=temp.size()||y>=temp.at(0).size()||temp[x][y]==0||temp[x][y]==-1)
                                        continue;

                                if(temp[x][y]==target) {
                                        sx=x;
                                        sy=y;
                                        return current_steps;
                                }

                                temp[x][y]=-1;
                                q.push({x,y});
                        }
                }
                current_steps++;
        }
        return -1;
}
};
