#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>> target;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
                target.push_back(make_pair(i, j));
        }
    }
    for (auto t : target)
    {
        for (int i = 0; i < m; i++)
            matrix[i][t.second] = 0;

        for (int j = 0; j < n; j++)
            matrix[t.first][j] = 0;
    }
}
int main()
{
    // vector<vector<int>> matrix = {
    //     {1, 1, 1},
    //     {1, 0, 1},
    //     {1, 1, 1}};
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}