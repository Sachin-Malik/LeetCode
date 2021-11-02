// You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations
// went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average
// value of the n + m rolls.
// You are given an integer array rolls of length m where rolls[i] is the value of the ith observation.
// You are also given the two integers mean and n.

class Solution {
public:
vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        vector<int> res;
        int m=rolls.size(),currentSum=0,requiredSum=0,totalSum=0,rem=0,currentRoll=0;

        for(int i=0; i<m; i++)
                currentSum+=rolls[i];
        totalSum=(m+n)*mean;

        // HANDLE A FEW EDGE CASES
        if(totalSum<requiredSum)
                return {};

        requiredSum=totalSum-currentSum;
        if(requiredSum>(n*6)||requiredSum<n)
                return {};

        // THERE EXISTS A SOLUTION FOR THIS CASE
        rem=requiredSum%n;
        currentRoll=requiredSum/n;

        for(int i=0; i<n; i++)
                res.push_back(currentRoll);

        for(int i=0; i<rem; i++)
                res[i]+=1;

        return res;
}
};
