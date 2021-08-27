class Solution {
public:
int maximumRemovals(string s, string p, vector<int>& removable) {
        int left=0,right=removable.size()-1;
        int max_k=INT_MIN,mid;

        while(left<=right) {
                mid=(left+right)/2;
                if(is_subsequence(s,p,mid,removable)) {
                        left=mid+1;
                        max_k=max(max_k,mid);
                }else{
                        right=mid-1;
                }
        }
        return max_k;
}

bool is_subsequence(string &s,string&p,int &mid,vector<int>&removable){
        unordered_map<int,int> umap;
        for(int i=0; i<mid; i++) {
                umap[removable[i]]=true;
        }

        int p1=0,p2=0;
        while(p1<s.length()&&p2<p.length()) {
                if(umap.find(p1)!=umap.end()) {
                        p1++;
                        continue;
                }
                if(s[p1]==p[p2]) {
                        p1++,p2++;
                }
                else
                        p1++;
        }
        return p2==p.length();
}
};
