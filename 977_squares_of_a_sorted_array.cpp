#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

// //Solution 1 time O(N)
// vector<int> sortedSquares(vector<int> &nums)
// {
//     int pos_idx;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] >= 0)
//         {
//             pos_idx = i;
//             break;
//         }
//     }

//     vector<int> temp1, temp2;
//     for (int i = 0; i < pos_idx; i++)
//         temp1.push_back(nums[i] * nums[i]);
//     std::reverse(temp1.begin(), temp1.end());

//     for (int i = pos_idx; i < nums.size(); i++)
//         temp2.push_back(nums[i] * nums[i]);

//     int x = 0, y = 0, idx = -1;
//     while (x < temp1.size() && y < temp2.size())
//     {
//         if (temp1[x] > temp2[y])
//             nums[++idx] = temp2[y++];
//         else
//             nums[++idx] = temp1[x++];
//     }

//     while (x < temp1.size())
//         nums[++idx] = temp1[x++];

//     while (y < temp2.size())
//         nums[++idx] = temp2[y++];

//     return nums;
// }

// Solution 2 more clean time O(N)
vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> output(n, 0);
    int left = 0, right = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {
        if (abs(nums[left]) < abs(nums[right]))
        {
            output[i] = nums[right] * nums[right];
            right--;
        }
        else
        {
            output[i] = nums[left] * nums[left];
            left++;
        }
    }
    return output;
}
void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << "  ";
    std::cout << std::endl;
}
int main()
{
    vector<int> input{-7, -3, 2, 3, 11};
    vector<int> output = sortedSquares(input);
    print(output);
    return 0;
}