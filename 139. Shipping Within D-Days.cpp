class Solution {
public:
int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,ans=INT_MAX;
        for(int i=0; i<weights.size(); i++) {
                sum+=weights[i];
        }
        int left=1,right=sum,mid=0;
        while(left<=right) {
                mid=(left+right)/2;
                if(check_with(mid,days,weights)) {
                        right=mid-1;
                        ans=min(ans,mid);
                }
                else
                        left=mid+1;
        }
        return ans;
}

bool check_with(int cap,int days,vector<int>&weight){
        int current_days=1;
        int current_weight=0;
        for(int i=0; i<weight.size(); i++) {

                if(weight[i]>cap)
                        return false;

                if(current_weight+weight[i]<=cap) {
                        current_weight+=weight[i];
                }else{
                        if(current_days>=days) {
                                return false;
                        }
                        else{
                                current_days++;
                                current_weight=weight[i];
                        }
                }
        }
        return true;
}
};
