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

//Second solution and much better in space complexity

class Solution {
public:
string intToRoman(int num) {

        string ans;
        if(num>=1000)
        {
                int k=num/1000;
                while(k--)
                        ans+='M';
                num%=1000;
        }
        if(num>=500)
        {
                if(num>=900)
                {
                        ans+="CM";
                        num%=900;
                }
                else
                {
                        ans+='D';
                        num%=500;
                }
        }
        if(num>=100)
        {
                if(num>=400)
                {
                        ans+="CD";
                        num%=400;
                }
                else
                {
                        int k=num/100;
                        while(k--)
                                ans+='C';
                        num%=100;
                }
        }
        if(num>=50)
        {
                if(num>=90)
                {
                        ans+="XC";
                        num%=90;
                }
                else
                {
                        ans+='L';
                        num%=50;
                }
        }
        if(num>=10)
        {
                if(num>=40)
                {
                        ans+="XL";
                        num%=40;
                }
                else
                {
                        int k=num/10;
                        while(k--)
                                ans+='X';
                        num%=10;
                }
        }
        if(num>=5)
        {
                if(num==9)
                {
                        ans+="IX";
                        num%=9;
                }
                else
                {
                        ans+='V';
                        num%=5;
                }
        }
        if(num>=1)
        {
                if(num==4)
                        ans+="IV";
                else
                {
                        while(num--)
                                ans+='I';
                }
        }
        return ans;
}
};
