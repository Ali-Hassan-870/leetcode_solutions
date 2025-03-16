#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int total_rows = matrix.size();
    int total_cols = matrix[0].size();
    int row = 0;
    int col = -1;
    int direction = 1;
    vector<int> output;

    while (total_rows > 0 && total_cols > 0)
    {
        for (int i = 0; i < total_cols; i++)
        {
            col += direction;
            output.push_back(matrix[row][col]);
        }
        total_rows--;

        for (int i = 0; i < total_rows; i++)
        {
            row += direction;
            output.push_back(matrix[row][col]);
        }
        total_cols--;

        direction *= -1;
    }
    return output;
}
int main()
{
    vector<vector<int>> input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> input2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> output = spiralOrder(input2);
    for (size_t i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
}