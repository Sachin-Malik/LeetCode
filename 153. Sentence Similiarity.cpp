class Solution {
public:
bool areSentencesSimilar(string s1, string s2) {
        int l1=s1.length();
        int l2=s2.length();

        vector<string> words1,words2;
        string current="";
        for(int i=0; i<=l1; i++) {

                if(i==l1||s1[i]==' ') {
                        words1.push_back(current);
                        current="";
                }else{
                        current+=s1[i];
                }
        }

        current="";
        for(int i=0; i<=l2; i++) {

                if(i==l2||s2[i]==' ') {
                        words2.push_back(current);
                        current="";
                }else{
                        current+=s2[i];
                }
        }
        int w1=words1.size();
        int w2=words2.size();
        int count=0;
        int p1=0,p2=0;
        while(p1<w1&&p2<w2&&words1[p1]==words2[p2]) {
                p1++,p2++,count++;
        }


        p1=w1-1,p2=w2-1;
        while(p1>=0&&p2>=0&&words1[p1]==words2[p2])
        {
                p1--,p2--;
                count++;
        }
        if(count>=min(w1,w2))
                return true;
        return false;


}
};
