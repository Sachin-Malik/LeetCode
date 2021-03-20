// Ques->Self explanatory
// range->0<=num<=3999
class Solution {
public:
string intToRoman(int num) {
        unordered_map<int,string> lookup;
        lookup[1]="I";
        lookup[2]="II";
        lookup[3]="III";
        lookup[4]="IV";
        lookup[5]="V";
        lookup[6]="VI";
        lookup[7]="VII";
        lookup[8]="VIII";
        lookup[9]="IX";
        lookup[10]="X";
        lookup[20]="XX";
        lookup[30]="XXX";
        lookup[40]="XL";
        lookup[50]="L";
        lookup[60]="LX";
        lookup[70]="LXX";
        lookup[80]="LXXX";
        lookup[90]="XC";
        lookup[100]="C";
        lookup[200]="CC";
        lookup[300]="CCC";
        lookup[400]="CD";
        lookup[500]="D";
        lookup[600]="DC";
        lookup[700]="DCC";
        lookup[800]="DCCC";
        lookup[900]="CM";
        lookup[1000]="M";
        lookup[2000]="MM";
        lookup[3000]="MMM";
        int i=0;
        string res="";

        int val=0;
        int rem=0;
        while(num>0)
        {
                rem=num%10;
                val=rem*pow(10,i);
                i++;
                res=lookup[val]+res;
                num=num/10;
        }
        return res;
}
};
