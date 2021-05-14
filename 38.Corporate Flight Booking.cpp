class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> output(n);
        for (int i = 0; i < n; i++)
        {
            output[i] = 0;
        }
        for (int i = 0; i < bookings.size(); i++)
        {
            int first = bookings[i][0] - 1;
            int last = bookings[i][1];
            output[first] = output[first] + bookings[i][2];
            if (last < n)
                output[last] = output[last] - bookings[i][2];
        }
        for (int i = 1; i < n; i++)
        {
            output[i] = output[i] + output[i - 1];
        }
        return output;
    }
};