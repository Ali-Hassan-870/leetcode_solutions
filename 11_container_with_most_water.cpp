#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> &height)
{
    int i = 0;
    int j = height.size() - 1;
    int maxWaterArea = 0;

    while (i <= j)
    {
        int min_height = min(height[i], height[j]);
        int width = j - i;
        maxWaterArea = max(maxWaterArea, (min_height * width));
        if (height[i] < height[j])
            i++;
        else
            j--;
    }
    return maxWaterArea;
}

int main()
{
    vector<int> input = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(input) << endl;
    return 0;
}