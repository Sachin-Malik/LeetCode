class Solution {
public:
int ans=INT_MAX,val=INT_MAX,max_val=INT_MIN;
int findBestValue(vector<int>& arr, int target) {

        int n=arr.size();
        for(int i=0; i<n; i++) {
                max_val=max(max_val,arr[i]);
        }

        int left=0,right=max_val,mid;
        while(left<=right) {

                mid=(left+right)/2;
                if(check_for(mid,target,arr))
                        right=mid-1;
                else
                        left=mid+1;
        }
        return val;
}

bool check_for(int mid,int target,vector<int>&arr){

        int sum=0;
        for(int i=0; i<arr.size(); i++) {
                arr[i]>mid?sum+=mid:sum+=arr[i];
        }

        if(abs(target-sum)<ans) {
                val=mid;
                ans=abs(target-sum);
        }
        else if(abs(target-sum)==ans&&val>mid) {
                val=mid;
                ans=abs(target-sum);
        }

        if(sum>=target)
                return true;
        return false;
}
};
