#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using std::vector;

int minTimeToVisitAllPoints(vector<vector<int>> &points)
{
    if (points.size() == 1)
        return 0;

    int time = 0;
    for (int i = 0; i < points.size() - 1; i++)
    {
        int x_coor_diff = abs(points[i][0] - points[i + 1][0]);
        int y_coor_diff = abs(points[i][1] - points[i + 1][1]);
        time += std::max(x_coor_diff, y_coor_diff);
    }
    return time;
}

int main()
{
    // std::vector<std::vector<int>> input = {{1, 1}, {3, 4}, {-1, 0}};
    vector<vector<int>> input = {{3, 2}, {-2, 2}};
    std::cout << minTimeToVisitAllPoints(input) << std::endl;
    return 0;
}