class Solution {
public:
string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26,0);
        for(int i=0; i<s.length(); i++) {
                freq[s[i]-'a']++;
        }

        string res="";

        for(int i=25; i>=0; i--) {
                int currentFreq=freq[i];
                if(currentFreq>0) {
                        while(currentFreq>0) {
                                //if currentFreq is less than repeatLimit then just print this
                                if(currentFreq<=repeatLimit) {
                                        for(int j=0; j<currentFreq; j++)
                                                res.push_back(char(i+'a'));
                                        currentFreq=0;
                                }else{
                                        for(int j=0; j<repeatLimit; j++) {
                                                res.push_back(char(i+'a'));
                                        }
                                        //now see if we can use this char some more
                                        int nextGreater=getNextGreater(i-1,freq);

                                        if(nextGreater==-1)
                                                break;
                                        res.push_back(char(nextGreater+'a'));
                                        currentFreq-=repeatLimit;
                                }
                        }
                }
        }
        return res;
}

int getNextGreater(int start,vector<int>&freq){
        if(start<0)
                return -1;

        for(int i=start; i>=0; i--) {
                if(freq[i]>=1) {
                        freq[i]--;
                        return i;
                }
        }
        return -1;
}
};
