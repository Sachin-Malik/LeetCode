class Solution {
public:
int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {

        priority_queue<pair<int,int> >pq;
        unordered_map<int,int> used;

        int n=values.size(),sum=0,elements=0;
        pair<int,int> current;
        for(int i=0; i<n; i++)
                pq.push({values[i],labels[i]});


        while(elements!=num_wanted&&pq.size()>0)
        {
                current=pq.top();
                if(used.find(current.second)!=used.end())
                {
                        if(used[current.second]<use_limit)
                        {
                                used[current.second]++;
                                sum+=current.first;
                                elements++;
                        }
                }
                else{
                        used[current.second]++;
                        sum+=current.first;
                        elements++;

                }
                pq.pop();
        }
        return sum;
}
};
