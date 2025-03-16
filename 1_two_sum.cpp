#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/* Solution no 1: Brute force approach, Time O(n^2) space O(1).
We simply check all possible pairs to find the result using 2 for loops. */
vector<int> twoSum1(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
                return {i, j};
        }
    }
    return {};
}

/* Solution no 2: Hashmap approach, Time O(n) space O(n). */
vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> numsHash;

    for (int i = 0; i < nums.size(); i++)
    {
        int temp = target - nums[i];
        if (numsHash.count(temp))
            return {numsHash[temp], i};

        numsHash[nums[i]] = i;
    }
    return {};
}
int main()
{
    vector<int> input = {3, 3, 4, 5, 6, 7, 8};
    vector<int> result = twoSum(input, 10);

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}