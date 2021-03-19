// Given n non-negative integers representing an elevation map where the width of each bar is 1,
//compute how much water it can trap after raining.


class Solution {
public:
int trap(vector<int>& height) {

        int n=height.size();
        if(n<=2)
                return 0;
        vector<int> lMax(n,0);
        lMax[0]=height[0];
        vector<int> rMax(n,0);
        rMax[n-1]=height[n-1];
        int leftMaxVal=height[0];
        int rightMaxVal=height[n-1];

        for(int i=1; i<n; i++)
        {
                lMax[i]=leftMaxVal;
                if(height[i]>leftMaxVal)
                        leftMaxVal=height[i];
        }
        for(int j=n-2; j>=0; j--)
        {
                rMax[j]=rightMaxVal;
                if(height[j]>rightMaxVal)
                        rightMaxVal=height[j];
        }

        int waterTrapped=0;
        for(int i=1; i<n-1; i++)
                if(height[i]<min(lMax[i],rMax[i]))
                        waterTrapped=waterTrapped+(min(lMax[i],rMax[i])-height[i]);


        return waterTrapped;
}
};
