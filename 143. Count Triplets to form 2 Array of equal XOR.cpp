class Solution {
public:
int countTriplets(vector<int>& arr) {
        int ans=0,n=arr.size();

        vector<int> prefix(n,0);
        int current=0;

        int left,right;
        for(int i=0; i<n; i++) {
                prefix[i]=current^arr[i];
                current=prefix[i];
        }

        for(int i=0; i<n-1; i++) {
                for(int j=i+1; j<n; j++) {
                        if(i==0)
                                left=0;
                        else
                                left=prefix[i-1];

                        right= prefix[j]^left;

                        if(right==0) {
                                ans+=(j-i);
                        }
                }
        }

        return ans;
}
};
