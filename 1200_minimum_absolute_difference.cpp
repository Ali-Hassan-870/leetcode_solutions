#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;

vector<vector<int>> minmumAbsDifference(vector<int> &arr)
{
    int n = arr.size();
    std::sort(std::begin(arr), std::end(arr));

    int min_diff = INT32_MAX;
    vector<vector<int>> output;
    for (int i = 0, j = 1; j < n; i++, j++)
    {
        if (arr[j] - arr[i] < min_diff)
            min_diff = arr[j] - arr[i];
    }

    for (int i = 0, j = 1; j < n; i++, j++)
    {
        if (arr[j] - arr[i] == min_diff)
            output.push_back({arr[i], arr[j]});
    }

    return output;
}
void print(vector<vector<int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
            std::cout << arr[i][j] << "  ";
        std::cout << std::endl;
    }
}
int main()
{
    vector<int> input = {4,1,2,3};
    vector<vector<int>> result = minmumAbsDifference(input);
    print(result);
    return 0;
}