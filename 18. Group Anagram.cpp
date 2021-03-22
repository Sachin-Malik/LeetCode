
// Given an array of strings strs, group the anagrams together.You can return the answer in any order.


class Solution {
public:
vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string,vector<string> > umap;
        int strings=strs.size();
        for(int i=0; i<strings; i++)
        {
                string sample=strs[i];
                sort(sample.begin(),sample.end());
                umap[sample].push_back(strs[i]);
        }
        for(auto p:umap)
                res.push_back(p.second);

        return res;
}
};
