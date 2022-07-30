class Solution {
public:

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> res;
        vector<int> maxFreq(26,0);
        vector<int> temp(26,0);

        for(int i=0; i<words2.size(); i++) {
                for(int j=0; j<26; j++)
                        temp[j]=0;

                for(int j=0; j<words2[i].size(); j++)
                        temp[words2[i][j]-'a']++;

                for(int j=0; j<26; j++)
                        maxFreq[j]=max(maxFreq[j],temp[j]);

        }

        for(int i=0; i<26; i++) {
                cout<<maxFreq[i]<<" ";
        }
        cout<<endl;

        for(int i=0; i<words1.size(); i++) {

                for(int j=0; j<26; j++)
                        temp[j]=0;

                for(int j=0; j<words1[i].size(); j++)
                        temp[words1[i][j]-'a']+=1;

                bool solution=true;
                for(int j=0; j<26; j++) {
                        if(temp[j]<maxFreq[j]) {
                                solution=false;
                                break;
                        }
                }

                if(solution) res.push_back(words1[i]);
        }
        return res;
}
};
