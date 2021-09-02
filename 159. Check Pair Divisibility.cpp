class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {

        long long int n = arr.size();
        unordered_map<long long int, long long int> count;
        for (int i = 0; i < n; i++)
        {
            long long int val = ((arr[i] % k) + k) % k;
            count[val]++;
        }

        for (auto it = count.begin(); it != count.end(); it++)
        {
            //if the count of this element is greater than 0
            long long int num = it->first;
            if (num == 0)
            {
                if (count[num] & 1)
                    return false;
                continue;
            }
            if (it->second > 0)
            {
                long long int rem = k - num;
                if (count[rem] != it->second)
                    return false;
                count[rem] -= it->second;
                it->second = 0;
            }
        }
        return true;
    }
};