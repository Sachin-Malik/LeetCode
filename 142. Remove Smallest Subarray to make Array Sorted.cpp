class Solution {
public:
int findLengthOfShortestSubarray(vector<int>& arr) {

        vector<int> left,right;
        left.push_back(arr[0]);

        int n=arr.size();
        if(n==1)
                return 0;
        for(int i=1; i<n; i++)
                if(arr[i]>=left.back())
                        left.push_back(arr[i]);
                else
                        break;

        if(left.size()==n)
                return 0;

        right.push_back(arr[n-1]);
        for(int i=n-2; i>=0; i--)
                if(arr[i]<=right.back())
                        right.push_back(arr[i]);
                else
                        break;


        reverse(right.begin(),right.end());
        if(right.size()==n)
                return 0;

        int element_remove=min(n-left.size(),n-right.size());
        int mini;
        for(int i=0; i<left.size(); i++) {
                int other=lower_bound(right.begin(),right.end(),left[i])-right.begin();
                if(other>=n)
                        mini=0;
                mini=int(right.size()-other);
                element_remove=min(element_remove,n-(i+1)-mini);
        }
        return element_remove;
}
};
