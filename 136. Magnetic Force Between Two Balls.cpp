class Solution {
public:
int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int left=1,right=1e9+7;

        while(left<right) {
                int mid=(left+right+1)/2;
                if(can_place_mid(mid,position,m))
                        left=mid;
                else
                        right=mid-1;
        }
        return left;
}

bool can_place_mid(int mid,vector<int>&position,int balls){

        int total=1,prev=position[0];
        for(int i=1; i<(int)position.size(); i++) {
                if(position[i]-prev>=mid) {
                        total++;
                        prev=position[i];
                }
        }
        return total>=balls;
}
};
