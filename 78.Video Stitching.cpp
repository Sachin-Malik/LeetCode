class Solution {
public:
static bool sortcol(vector<int>&v1,vector<int>&v2)
{
        if(v1[0]<v2[0])
                return true;
        if(v1[0]>v2[0])
                return false;
        if(v1[1]>=v2[1])
                return true;
        return false;
}
int videoStitching(vector<vector<int> >& clips, int time) {

        sort(clips.begin(),clips.end(),sortcol);
        int clips_req=1, min_val=clips[0][0],max_val=clips[0][1];
        if(min_val!=0)
                return -1;

        for(int i=1; i<clips.size();)
        {
                if(max_val>=time)
                        return clips_req;
                //disjoint
                if(clips[i][0]>max_val)
                        return -1;

                if(clips[i][1]>max_val)
                {
                        int temp=i,c_max=max_val,n_max=max_val;
                        while(temp<clips.size()&&clips[temp][0]<=c_max)
                        {
                                n_max=max(n_max,clips[temp][1]);
                                temp++;
                        }
                        max_val=n_max;
                        i=temp;
                        clips_req++;
                }
                else
                        i++;
        }

        if(max_val<time)
                return -1;

        return clips_req;

}
};
