#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <string>

using std::pair;
using std::queue;
using std::string;
using std::to_string;
using std::unordered_set;
using std::vector;

/* 
Approach:
- Use BFS to explore each island starting from any unvisited '1'.
- The visited set stores unique string keys ("row,col") to track visited cells.
- For each unvisited '1', we trigger BFS to mark all connected '1's as visited.
- Each BFS initiation corresponds to a new island, hence we increment the count.
*/

void bfs(int row, int col, unordered_set<string> &visited, vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    visited.insert(to_string(row) + "," + to_string(col));

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rows = grid.size();
    int cols = grid[0].size();

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
        int r = current.first;
        int c = current.second;

        for (auto &dir : directions)
        {
            int new_r = r + dir.first;
            int new_c = c + dir.second;

            string key = to_string(new_r) + "," + to_string(new_c);
            if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && grid[new_r][new_c] == '1' && visited.find(key) == visited.end())
            {
                visited.insert(to_string(new_r) + "," + to_string(new_c));
                q.push({new_r, new_c});
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    unordered_set<string> visited;
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            string key = to_string(i) + "," + to_string(j);
            if (grid[i][j] == '1' && visited.find(key) == visited.end())
            {
                bfs(i, j, visited, grid);
                ++count;
            }
        }
    }
    return count;
}

int main()
{
    // vector<vector<char>> input = {
    //     {'1', '1', '1', '1', '0'},
    //     {'1', '1', '0', '1', '0'},
    //     {'1', '1', '0', '0', '0'},
    //     {'0', '0', '0', '0', '0'}};
    vector<vector<char>> input = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    std::cout << numIslands(input) << std::endl;
    return 0;
}