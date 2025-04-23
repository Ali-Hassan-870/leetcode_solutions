#include <iostream>
#include <vector>
#include <algorithm>

using std::max;
using std::vector;

int longestMountain(vector<int> &arr)
{
    int n = arr.size();
    int result = 0;

    for (int i = 1; i < n - 1; i++)
    {
        // Check if arr[i] is a peak
        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            int left = i, right = i;

            // Move right pointer to the end of the descending slope
            while (right < n - 1 && arr[right] > arr[right + 1])
                right++;

            // Move left pointer to the start of the ascending slope
            while (left > 0 && arr[left] > arr[left - 1])
                left--;

            // Update the max mountain length
            result = max(result, right - left + 1);

            // Skip checked elements inside the mountain
            i = right;
        }
    }
    return result;
}


int main()
{
    vector<int> input = {1, 2, 3, 2, 1, 0, 2, 1, 2, 3, 4, 0, 1};
    std::cout << longestMountain(input) << std::endl;
    return 0;
}