// Ques No. 451
// Given a string s, sort it in decreasing order based on the frequency of characters, and return the sorted string.

class Solution {
public:
string frequencySort(string s) {

        int len=s.length();
        unordered_map<char,int> umap;
        for(int i=0; i<len; i++)
                umap[s[i]]++;

        priority_queue<pair<int,char> >pq;
        for(auto i:umap)
                pq.push(make_pair(i.second,i.first));

        string res="";
        while(pq.size())
        {
                int f=pq.top().first;
                char c=pq.top().second;
                for(int i=0; i<f; i++)
                        res+=c;
                pq.pop();
        }
        return res;

}
};
