class Solution
{
public:
    int integerBreak(int n)
    {
        vector<int> products(59, 0);
        products[0] = 1;
        products[1] = 1;
        products[2] = 1;
        products[3] = 2;

        for (int i = 4; i <= n; i++)
        {
            int temp = INT_MIN, l, r, product;
            for (int j = 1; j < i; j++)
            {
                l = max(j, products[j]);
                r = max(i - j, products[i - j]);
                result = l * r;
                temp = max(result, temp);
            }
            products[i] = temp;
        }
        return products[n];
    }
};