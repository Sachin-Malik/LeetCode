class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {

        map<int, int> flowersInBloom;
        for (int i = 0; i < flowers.size(); i++)
        {
            flowersInBloom[flowers[i][0]] += 1;
            flowersInBloom[flowers[i][1] + 1] -= 1;
        }

        vector<vector<int>> temp;
        int sum = 0;
        for (auto ele : flowersInBloom)
        {
            sum += ele.second;
            temp.push_back({ele.first, sum});
        }

        vector<int> result;
        for (int i = 0; i < people.size(); i++)
        {
            if (people[i] < temp[0][0])
                result.push_back(0);
            else if (people[i] > temp[temp.size() - 1][0])
                result.push_back(0);
            else
                result.push_back(getFlowers(people[i], temp));
        }

        return result;
    }

    int getFlowers(int time, vector<vector<int>> &flowers)
    {

        int l = 0;
        int r = flowers.size() - 1;

        int ans = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (flowers[mid][0] <= time)
            {
                ans = flowers[mid][1];
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }

            if (mid == l && mid == r)
                break;
        }
        return ans;
    }
};