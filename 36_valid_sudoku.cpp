#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*straight forward nested loops solution*/
bool isValidSudoku1(vector<vector<char>> &board)
{
    int n = board.size();
    vector<int> map(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
                continue;
            map[board[i][j]]++;
            if (map[board[i][j]] > 1)
                return false;
        }
        map.clear();
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[j][i] == '.')
                continue;
            map[board[j][i]]++;
            if (map[board[j][i]] > 1)
                return false;
        }
        map.clear();
    }
    int m = 3;
    for (int box_row = 0; box_row < m; box_row++)
    {
        for (int box_col = 0; box_col < m; box_col++)
        {
            map.clear();
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    int row = box_row * m + i;
                    int col = box_col * m + j;
                    if (board[row][col] == '.')
                        continue;
                    map[board[row][col]]++;
                    if (map[board[row][col]] > 1)
                        return false;
                }
            }
        }
    }

    return true;
}

/*More optimized and efficient solution*/

bool isValidSudoku(vector<vector<char>> &board)
{
    const int n = 9;
    bool rows[n][n] = {false};
    bool columns[n][n] = {false};
    bool sub_boxes[n][n] = {false};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
                continue;

            int index = board[i][j] - '0' - 1;
            int sub_box_index = (i / 3) * 3 + (j / 3);

            if (rows[i][index] || columns[j][index] || sub_boxes[sub_box_index][index])
                return false;

            rows[i][index] = true;
            columns[j][index] = true;
            sub_boxes[sub_box_index][index] = true;
        }
    }
    return true;
}
int main()
{
    vector<vector<char>> input =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    vector<vector<char>> board = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << isValidSudoku(input) << endl;
}