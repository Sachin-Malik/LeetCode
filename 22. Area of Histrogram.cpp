class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 0)
                return 0;

        stack<int> S;

        int L[n];
        int R[n];

        for(int i=0; i<n; i++) {
                while(!S.empty() && heights[S.top()] >= heights[i])
                        S.pop();

                L[i] = S.empty() ? -1 : S.top();
                S.push(i);
        }

        while(!S.empty()) S.pop();
        for(int i=n-1; i>=0; i--) {
                while(!S.empty() && heights[S.top()] >= heights[i])
                        S.pop();

                R[i] = S.empty() ? n : S.top();
                S.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++)
                ans = max(ans, (R[i]-L[i]-1) * heights[i]);
        return ans;
}
};
