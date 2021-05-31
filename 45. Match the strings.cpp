class Solution
{
public:
int minimumSwap(string s1, string s2)
{
        int sl1 = s1.length();
        if (s2.length() != sl1)
                return -1;

        int counter = 0, xy = 0, yx = 0;
        for (int i = 0; i < sl1; i++)
        {
                if (s1[i] != s2[i])
                {
                        if (s1[i] == 'x')
                                xy++;
                        else
                                yx++;
                }
        }

        counter += xy / 2;
        counter += yx / 2;

        int r1 = xy % 2;
        int r2 = yx % 2;
        if ((r1 + r2) % 2)
                return -1;
        else if (r1 == 1 && r2 == 1)
                counter += 2;
        return counter;
}
};
