#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    int length = 1;
    unordered_set<int> set;

    for (int i = 0; i < nums.size(); i++)
        set.insert(nums[i]);

    nums.clear();
    for (int num : set)
        nums.push_back(num);

    for (int i = 0; i < nums.size(); i++)
    {
        if (set.find(nums[i] + 1) != set.end() || set.find(nums[i] - 1) != set.end())
        {
            length++;
        }
    }
    return length - 1;
}

int main()
{
    vector<int> input = {-1, -2, -3, -4, 10, 11, 12};
    cout << longestConsecutive(input) << endl;
    return 0;
}