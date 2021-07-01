class TopVotedCandidate {
public:
unordered_map<int,int> votes;
vector<int> in_lead;
vector<int> my_times;
int last_vote_at=0;
TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int n=times.size();
        my_times=times;
        last_vote_at=times[n-1];
        int max_val=INT_MIN;

        max_val=0;
        int person=-1;
        for(int i=0; i<n; i++)
        {
                votes[persons[i]]++;
                if(votes[persons[i]]>=max_val)
                {
                        max_val=votes[persons[i]];
                        person=persons[i];
                }
                in_lead.push_back(person);
        }

}

int q(int t) {

        //binary search
        if(t>=last_vote_at)
                return in_lead[in_lead.size()-1];
        return in_lead[find_just_smaller(t,0,in_lead.size()-1)];
}
int find_just_smaller(int target,int l,int r)
{
        int mid=(l+r)/2;
        if(my_times[mid]==target)
                return mid;

        if(l==r)
                return l-1;

        if(my_times[mid]>target)
                return find_just_smaller(target,0,mid);

        else
                return find_just_smaller(target,mid+1,r);
}
};
