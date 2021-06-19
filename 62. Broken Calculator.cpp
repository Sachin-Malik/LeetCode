class Solution {
public:
int brokenCalc(int x, int y) {
        if(x>=y)
                return x-y;
        int operations=0,diff=x-y,divide=0,temp=y,odd=0;

        while(temp>x)
        {
                if(temp%2==1) {
                        odd++;
                        temp++;
                }
                divide++;
                temp=temp/2;
        }
        int down=(x-temp)+odd+divide;

        return down;

}

};
