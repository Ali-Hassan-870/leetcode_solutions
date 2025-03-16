#include<iostream>
#include<vector>
using namespace std;

void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(board[i][j]==0)
            {
                int temp;
                if(j>0&&board[i-1][j-1]%2==1)
                {
                    temp++;
                }
                if(j<n&&board[i+1][j+1]%2==1)
                {
                    temp++;
                }
            }
            else
            {

            }
        }
        
    }
    
}