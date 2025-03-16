#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int upper_row = 0;
    int lower_row = n - 1;

    while (upper_row < lower_row)
        swap(matrix[upper_row++], matrix[lower_row--]);

    for (int row = 0; row < n; row++)
        for (int col = row + 1; col < n; col++)
            swap(matrix[row][col], matrix[col][row]);
}
int main()
{
    // vector<vector<int>> input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> input = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    rotate(input);
    for (size_t i = 0; i < input.size(); i++)
    {
        for (size_t j = 0; j < input.size(); j++)
        {
            cout << input[i][j] << "  ";
        }
        cout << endl;
    }
}