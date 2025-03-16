#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0, right = 0, sum = 0;
    int min_len = INT32_MAX;

    while (right < nums.size())
    {
        sum += nums[right];
        while (sum >= target)
        {
            min_len = min(min_len, (right - left) + 1);
            sum -= nums[left++];
        }
        right++;
    }
    return min_len == INT32_MAX ? 0 : min_len;
}
int main()
{
    vector<int> input = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << minSubArrayLen(11, input) << endl;
    return 0;
}