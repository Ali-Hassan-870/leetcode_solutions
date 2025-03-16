#include <iostream>
#include <vector>
using namespace std;

/*Solution No 1: Time complexity O(N) and space complexity O(1).
In this we traverse the height array using two pointers aproach.*/
int trap(vector<int> &height)
{
    int n = height.size();

    if (n <= 2)
        return 0;

    int i = 0;
    int j = n - 1;
    int left_max = height[i];
    int right_max = height[j];
    int trapped_water = 0;

    while (i < j)
    {
        if (left_max <= right_max)
        {
            trapped_water += (left_max - height[i]);
            i++;
            left_max = max(left_max, height[i]);
        }
        else
        {
            trapped_water += (right_max - height[j]);
            j--;
            right_max = max(right_max, height[j]);
        }
    }
    return trapped_water;
}

/*Soltuion no 2: Time O(N) and Space O(N).

This solution take three vector leftMax, rightMax and water to keep track of the trapped water at each height. The benifit of this solution is that we can make an array that tells us the water trapped at each height.*/
int trap2(vector<int> &height)
{
    int n = height.size();
    vector<int> leftMax(n, 0);
    vector<int> rightMax(n, 0);
    vector<int> water(n, 0);

    int i = 0, j = 0;

    while (j < height.size())
    {
        if (height[i] < height[j])
        {
            i = j;
            leftMax[j++] = height[i];
        }
        else
            leftMax[j++] = height[i];
    }

    i = j = (n - 1);

    while (j >= 0)
    {
        if (height[i] < height[j])
        {
            i = j;
            rightMax[j--] = height[i];
        }
        else
            rightMax[j--] = height[i];
    }

    int trapped_water = 0;
    for (int i = 0; i < n; i++)
    {
        water[i] = min(leftMax[i], rightMax[i]) - height[i];
        trapped_water += water[i];
    }

    return trapped_water;
}
int main()
{
    vector<int> input = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap2(input) << endl;
    // trap2(input);
}