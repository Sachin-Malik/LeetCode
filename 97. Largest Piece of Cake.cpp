class Solution {
public:
long long MOD=1000000007;
int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);

        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());

        int prev=0,horizontal_max=0,vertival_max=0;
        for(int i=0; i<horizontalCuts.size(); i++) {
                horizontal_max=max(horizontal_max,horizontalCuts[i]-prev);
                prev=horizontalCuts[i];
                horizontal_max%=MOD;
        }

        prev=0;
        for(int i=0; i<verticalCuts.size(); i++) {
                vertival_max=max(vertival_max,verticalCuts[i]-prev);
                prev=verticalCuts[i];
                vertival_max%=MOD;
        }

        horizontal_max%=MOD;
        vertival_max%=MOD;

        long long ans=horizontal_max*vertival_max;
        ans=ans%MOD;
        return (int)ans;
}
};
