class Solution
{
public:
    vector<vector<int>> offsets = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        queue<pair<int, int>> q;
        int rows = mat.size();
        int cols = mat.at(0).size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push(make_pair(i, j));
                }
                else
                {
                    mat[i][j] = -1;
                }
            }
        }

        int distance = 1;
        while (q.size())
        {
            int s = q.size();
            for (int m = 0; m < s; m++)
            {
                auto current = q.front();
                q.pop();
                int x = current.first;
                int y = current.second;
                for (int i = 0; i < offsets.size(); i++)
                {
                    int X = x - offsets[i][0];
                    int Y = y - offsets[i][1];

                    if (X < 0 || Y < 0 || X >= mat.size() || Y >= mat.at(0).size() || mat[X][Y] != -1)
                    {
                        continue;
                    }
                    mat[X][Y] = distance;
                    q.push({X, Y});
                }
            }
            distance++;
        }
        return mat;
    }
};